package com.gruppe6.rpcxmlgripper.impl;

import java.util.Locale;

import com.ur.urcap.api.contribution.ViewAPIProvider;
import com.ur.urcap.api.contribution.program.ContributionConfiguration;
import com.ur.urcap.api.contribution.program.CreationContext;
import com.ur.urcap.api.contribution.program.ProgramAPIProvider;
import com.ur.urcap.api.contribution.program.swing.SwingProgramNodeService;
import com.ur.urcap.api.domain.data.DataModel;

public class RPCXMLGripperProgramNodeService implements  SwingProgramNodeService<RPCXMLGripperProgramNodeContribution, RPCXMLGripperProgramNodeView>{

	public RPCXMLGripperProgramNodeService() {
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public String getId() {
		// TODO Auto-generated method stub
		return "RPCXMLGripper";
	}

	@Override
	public void configureContribution(ContributionConfiguration configuration) {
		// TODO Auto-generated method stub
		configuration.setChildrenAllowed(false);
	}

	@Override
	public String getTitle(Locale locale) {
		// TODO Auto-generated method stub
		return "XML-RPC Gripper";
	}

	@Override
	public RPCXMLGripperProgramNodeView createView(ViewAPIProvider apiProvider) {
		// TODO Auto-generated method stub
		return new RPCXMLGripperProgramNodeView(apiProvider);
	}

	@Override
	public RPCXMLGripperProgramNodeContribution createNode(ProgramAPIProvider apiProvider,
			RPCXMLGripperProgramNodeView view, DataModel model, CreationContext context) {
		// TODO Auto-generated method stub
		return new RPCXMLGripperProgramNodeContribution(apiProvider, view, model);
	}
	
}

