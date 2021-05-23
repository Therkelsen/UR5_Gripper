package com.gruppe6.rpcxmlgripper.impl;

import java.util.Locale;

import com.ur.urcap.api.contribution.ViewAPIProvider;
import com.ur.urcap.api.contribution.installation.ContributionConfiguration;
import com.ur.urcap.api.contribution.installation.CreationContext;
import com.ur.urcap.api.contribution.installation.InstallationAPIProvider;
import com.ur.urcap.api.contribution.installation.swing.SwingInstallationNodeService;
import com.ur.urcap.api.domain.SystemAPI;
import com.ur.urcap.api.domain.data.DataModel;

public class RPCXMLGripperInstallationNodeService implements SwingInstallationNodeService<RPCXMLGripperInstallationNodeContribution, RPCXMLGripperInstallationNodeView>{
	
	public RPCXMLGripperInstallationNodeService() {
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public void configureContribution(ContributionConfiguration configuration) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public String getTitle(Locale locale) {
		// TODO Auto-generated method stub
		return "XML-RPC Gripper";
	}

	@Override
	public RPCXMLGripperInstallationNodeView createView(ViewAPIProvider apiProvider) {
		// TODO Auto-generated method stub
		return new RPCXMLGripperInstallationNodeView(apiProvider);
	}

	@Override
	public RPCXMLGripperInstallationNodeContribution createInstallationNode(InstallationAPIProvider apiProvider,
			RPCXMLGripperInstallationNodeView view, DataModel model, CreationContext context) {
		// TODO Auto-generated method stub
		return new RPCXMLGripperInstallationNodeContribution(apiProvider, view, model);
	}

}
