package com.gruppe6.rpcxmlgripper.impl;

import com.ur.urcap.api.contribution.ProgramNodeContribution;
import com.ur.urcap.api.contribution.program.ProgramAPIProvider;
import com.ur.urcap.api.domain.data.DataModel;
//import com.ur.urcap.api.domain.program.nodes.builtin.IfNode;
import com.ur.urcap.api.domain.script.ScriptWriter;
import com.ur.urcap.api.domain.undoredo.UndoRedoManager;
import com.ur.urcap.api.domain.undoredo.UndoableChanges;

public class RPCXMLGripperProgramNodeContribution implements ProgramNodeContribution{
	
	private final ProgramAPIProvider apiProvider;
	private final RPCXMLGripperProgramNodeView view;
	private final DataModel model;
	private final UndoRedoManager undoRedoMgr;
	private static final String STATE = "state";
	boolean isConnected = false;
	
	
	public RPCXMLGripperProgramNodeContribution(ProgramAPIProvider apiProvider, RPCXMLGripperProgramNodeView view, DataModel model) {
		this.apiProvider = apiProvider;
		this.view = view;
		this.model = model;
		this.undoRedoMgr = apiProvider.getProgramAPI().getUndoRedoManager();
	}
	
	public void gripButtonClicked() {
		undoRedoMgr.recordChanges(new UndoableChanges() {
			
			@Override
			public void executeChanges() {
				model.set(STATE, 1);
				
			}
		});
	}
	
	public void releaseButtonClicked() {
		undoRedoMgr.recordChanges(new UndoableChanges() {
			
			@Override
			public void executeChanges() {
				model.set(STATE, 2);
				
			}
		});
		 
	}
	
	private int getSTATE() {
		return model.get(STATE, 0);
	} 
	
	private RPCXMLGripperInstallationNodeContribution getInstallation(){
		return apiProvider.getProgramAPI().getInstallationNode(RPCXMLGripperInstallationNodeContribution.class);
	}
	
	@Override
	public void openView() {
		view.setRadioButton(getSTATE());
		
	}

	@Override
	public void closeView() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public String getTitle() {
		// TODO Auto-generated method stub
		//System.out.println("getTitle() called;");
		String title = "Gripper mode:";
		switch (getSTATE()) {
		case 1:
			title += "Grip";
			break;
		case 2:
			title += "Release";
			break;
		default: 
			title += "Not defined";			
		}
		
		return title;
		
	}

	@Override
	public boolean isDefined() {
		// TODO Auto-generated method stub
		//System.out.println("isDefined called");
		return (getSTATE() != 0);
	}

	@Override
	public void generateScript(ScriptWriter writer) {
		// TODO Auto-generated method stub
		System.out.println("generateScript called");
		
		writer.ifCondition(getSTATE() +"== 1");
		writer.appendLine(getInstallation().getXMLRPCVariable() + ".secure_grip()");
		writer.elseCondition();
		writer.appendLine(getInstallation().getXMLRPCVariable() + ".release_grip()");
		writer.end();
		
		
	}
	

}
