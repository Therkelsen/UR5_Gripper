package com.gruppe6.rpcxmlgripper.impl;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import com.ur.urcap.api.contribution.ContributionProvider;
import com.ur.urcap.api.contribution.ViewAPIProvider;
import com.ur.urcap.api.contribution.installation.swing.SwingInstallationNodeView;
import com.ur.urcap.api.domain.userinteraction.inputvalidation.InputValidator;
import com.ur.urcap.api.domain.userinteraction.keyboard.KeyboardInputCallback;
import com.ur.urcap.api.domain.userinteraction.keyboard.KeyboardNumberInput;
import com.ur.urcap.api.domain.userinteraction.keyboard.KeyboardTextInput;

public class RPCXMLGripperInstallationNodeView implements SwingInstallationNodeView<RPCXMLGripperInstallationNodeContribution>{

	private final ViewAPIProvider apiProvider;
	private JTextField IPAdressInputField;
	private JTextField portNrInputField;
	
	public RPCXMLGripperInstallationNodeView(ViewAPIProvider apiProvider) {
		this.apiProvider = apiProvider;
	}
	
	@Override
	public void buildUI(JPanel panel, RPCXMLGripperInstallationNodeContribution contribution) {
		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
		
		//panel.add(createDescription("TEST"));
		panel.add(createIPInput(contribution));
		panel.add(createSpacer(15));
		panel.add(createPortInput(contribution));
	}
	
	private Box createDescription(String desc) {
		Box box = Box.createHorizontalBox();
		box.setAlignmentX(Component.LEFT_ALIGNMENT);
		
		JLabel label = new JLabel(desc);
		
		box.add(label);
		return box;
		
	}
	
	private Component createSpacer(int height) {
		return Box.createRigidArea(new Dimension(0, height));
	}
	
	
	private Box createIPInput(final RPCXMLGripperInstallationNodeContribution contribution) {
		Box box = Box.createHorizontalBox();
		box.setAlignmentX(Component.LEFT_ALIGNMENT);

		box.add(new JLabel("ENTER IP-ADRESS: "));
		
		IPAdressInputField = new JTextField();
		IPAdressInputField.setFocusable(false);
		IPAdressInputField.setPreferredSize(new Dimension(200, 20));
		IPAdressInputField.setMaximumSize(IPAdressInputField.getPreferredSize());
		IPAdressInputField.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				KeyboardTextInput keyboardInput = contribution.getIPInput();
				keyboardInput.show(IPAdressInputField, contribution.getCallbackForIP());
			}
				
		});
		box.add(IPAdressInputField);

		return box;
	}
	
	private Box createPortInput(final RPCXMLGripperInstallationNodeContribution contribution) {
		Box box = Box.createHorizontalBox();
		box.setAlignmentX(Component.LEFT_ALIGNMENT);

		box.add(new JLabel("ENTER PORT NUMBER: "));
		
		portNrInputField = new JTextField();
		portNrInputField.setFocusable(false);
		portNrInputField.setPreferredSize(new Dimension(200, 20));
		portNrInputField.setMaximumSize(portNrInputField.getPreferredSize());
		portNrInputField.addMouseListener(new MouseAdapter() {
			@Override
			public void mousePressed(MouseEvent e) {
				KeyboardNumberInput<Integer> keyboardInput = contribution.getPortInput();
				keyboardInput.show(portNrInputField, contribution.getCallbackForPort());
			}
		});
		box.add(portNrInputField);

		return box;
	}
	
	public void setIPText(String t) {
		IPAdressInputField.setText(t);
	}
	
	public void setPortText(String value) {
		portNrInputField.setText(value);;
	}




}
