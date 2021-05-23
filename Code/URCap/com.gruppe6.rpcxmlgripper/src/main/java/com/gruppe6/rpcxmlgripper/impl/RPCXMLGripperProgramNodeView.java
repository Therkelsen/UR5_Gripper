package com.gruppe6.rpcxmlgripper.impl;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.plaf.DimensionUIResource;

import com.ur.urcap.api.contribution.ContributionProvider;
import com.ur.urcap.api.contribution.ViewAPIProvider;
import com.ur.urcap.api.contribution.program.swing.SwingProgramNodeView;
import com.ur.urcap.api.domain.userinteraction.keyboard.KeyboardTextInput;

public class RPCXMLGripperProgramNodeView implements SwingProgramNodeView<RPCXMLGripperProgramNodeContribution>{
	
	private final ViewAPIProvider apiProvider;
	private final JLabel label = new JLabel();
	private final JRadioButton gripRadioButton = new JRadioButton("Grip");
	private final JRadioButton releaseRadioButton = new JRadioButton("Release");
	
	
	
	public RPCXMLGripperProgramNodeView(ViewAPIProvider apiProvider) {
		this.apiProvider = apiProvider;
		createButtonGroup();
	}
	

	@Override
	public void buildUI(JPanel panel, ContributionProvider<RPCXMLGripperProgramNodeContribution> provider) {
		// TODO Auto-generated method stub
		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
		
		panel.add(createDescription("Select behavior of gripper:"));
		panel.add(createSpacer(20));
		panel.add(createGripButton(provider));
		panel.add(createSpacer(5));
		panel.add(createReleaseButton(provider));
		panel.add(label);
		
	}
	
	private Box createDescription(String desc) {
		Box box = Box.createHorizontalBox();
		box.setAlignmentX(Component.LEFT_ALIGNMENT);
		
		JLabel label = new JLabel(desc);
		box.add(label);
		
		return box;
	}
	
	private Box createGripButton(final ContributionProvider<RPCXMLGripperProgramNodeContribution> provider) {
		Box box = Box.createHorizontalBox();
		box.setAlignmentX(Component.LEFT_ALIGNMENT);
		
		gripRadioButton.setPreferredSize(new Dimension(150, 60));
		gripRadioButton.setMaximumSize(gripRadioButton.getPreferredSize());
		gripRadioButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent click) {
				provider.get().gripButtonClicked();
				
			}
		});
		
		box.add(gripRadioButton);
		
		return box;
	}
	
	private Box createReleaseButton(final ContributionProvider<RPCXMLGripperProgramNodeContribution> provider) {
		Box box = Box.createHorizontalBox();
		box.setAlignmentX(Component.LEFT_ALIGNMENT);
		
		releaseRadioButton.setPreferredSize(new Dimension(150, 60));
		releaseRadioButton.setMaximumSize(releaseRadioButton.getPreferredSize());
		releaseRadioButton.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent click) {
				provider.get().releaseButtonClicked();
				
			}
		});
		
		
		box.add(releaseRadioButton);
		
		return box;
	}
	
	private void createButtonGroup() {
		
		ButtonGroup group = new ButtonGroup();
		group.add(gripRadioButton);
		group.add(releaseRadioButton);
		
	}
	
	
	private Component createSpacer(int height) {
		return Box.createRigidArea(new Dimension(0, height));
	}
	
	public void setRadioButton(int state) {
		switch (state) {
		case 1:
			gripRadioButton.setSelected(true);
			label.setText("");
			break;
		case 2:
			releaseRadioButton.setSelected(true);
			label.setText("");
			break;
		default: 
			label.setText("No action chosen");	
		}
	}

}
