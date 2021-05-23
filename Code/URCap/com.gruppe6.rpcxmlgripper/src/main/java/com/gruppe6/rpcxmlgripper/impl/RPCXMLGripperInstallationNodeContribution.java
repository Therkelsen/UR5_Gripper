package com.gruppe6.rpcxmlgripper.impl;

import com.ur.urcap.api.contribution.InstallationNodeContribution;
import com.ur.urcap.api.contribution.installation.InstallationAPIProvider;
import com.ur.urcap.api.domain.InstallationAPI;
import com.ur.urcap.api.domain.data.DataModel;
import com.ur.urcap.api.domain.script.ScriptWriter;
import com.ur.urcap.api.domain.userinteraction.inputvalidation.InputValidationFactory;
import com.ur.urcap.api.domain.userinteraction.keyboard.KeyboardInputCallback;
import com.ur.urcap.api.domain.userinteraction.keyboard.KeyboardInputFactory;
import com.ur.urcap.api.domain.userinteraction.keyboard.KeyboardNumberInput;
import com.ur.urcap.api.domain.userinteraction.keyboard.KeyboardTextInput;

public class RPCXMLGripperInstallationNodeContribution implements InstallationNodeContribution{
	
	private final InstallationAPIProvider apiProvider;
	private final RPCXMLGripperInstallationNodeView view;
	private final DataModel model;
	private KeyboardInputFactory keyboardInputFactory;
	private final InputValidationFactory inputValidationFactory;
	private static final String XMLRPC_VARIABLE = "XML-RPC variable";
	private static final String IPADRESS = "IP-adress";
	private static final String PORTNR = "Port number";

	public RPCXMLGripperInstallationNodeContribution(InstallationAPIProvider apiProvider, RPCXMLGripperInstallationNodeView view, DataModel model) {
		keyboardInputFactory = apiProvider.getUserInterfaceAPI().getUserInteraction().getKeyboardInputFactory();
		inputValidationFactory = apiProvider.getUserInterfaceAPI().getUserInteraction().getInputValidationFactory();
		this.apiProvider = apiProvider;
		this.view = view;
		this.model = model;
	}
	
	
	public KeyboardTextInput getIPInput() {
		KeyboardTextInput keyboardInput = keyboardInputFactory.createIPAddressKeyboardInput();
		return keyboardInput;
		
	}
	
	public KeyboardInputCallback<String> getCallbackForIP() {
		return new KeyboardInputCallback<String>() {

			@Override
			public void onOk(String value) {
				view.setIPText(value);
				model.set(IPADRESS, value);
			}
		}; 
	}
	
	public KeyboardNumberInput<Integer> getPortInput() {
		KeyboardNumberInput<Integer> keyboardInput = keyboardInputFactory.createPositiveIntegerKeypadInput();
		keyboardInput.setErrorValidator(inputValidationFactory.createIntegerRangeValidator(0,99999));
		return keyboardInput;
	
	}
	
	
	public KeyboardInputCallback<Integer> getCallbackForPort() {
		return new KeyboardInputCallback<Integer>() {

			@Override
			public void onOk(Integer value) {
				view.setPortText(value.toString());
				model.set(PORTNR, value.toString());
			}
		};
	}

	
	private String getIPAdress() {
		return model.get(IPADRESS, "None");
	} 
	
	private String getPortNr() {
		return model.get(PORTNR, "None");
	}
	
	public String getXMLRPCVariable(){
		return XMLRPC_VARIABLE;
	}
	
	
	
	@Override
	public void openView() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void closeView() {
		// TODO Auto-generated method stub
		
		
	}

	@Override
	public void generateScript(ScriptWriter writer) {
		//System.out.println("generateScript from installation called");
		writer.assign(XMLRPC_VARIABLE, "rpc_factory(\"xmlrpc\", \"http://" + getIPAdress() + ":" + getPortNr() + "/RPC2\")");

		
	}
	

	
}
