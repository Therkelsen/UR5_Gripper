package com.gruppe6.rpcxmlgripper.impl;

import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;

import com.ur.urcap.api.contribution.installation.swing.SwingInstallationNodeService;
import com.ur.urcap.api.contribution.program.swing.SwingProgramNodeService;

/**
 * Hello world activator for the OSGi bundle URCAPS contribution
 *
 */
public class Activator implements BundleActivator {
	@Override
	public void start(BundleContext bundleContext) throws Exception {
		System.out.println("RPC/XML Gripper registering");
		
		bundleContext.registerService(SwingProgramNodeService.class, new RPCXMLGripperProgramNodeService(), null);
		bundleContext.registerService(SwingInstallationNodeService.class, new RPCXMLGripperInstallationNodeService(), null);
	}

	@Override
	public void stop(BundleContext bundleContext) throws Exception {
		System.out.println("RPC/XML Gripper closing");
	}
}

