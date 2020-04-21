<distribution version="12.0.1" name="PCOM" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{A250053C-6F3E-4EE0-9938-E60A0A46DFE7}">
		<general appName="PCOM" outputLocation="d:\Proyectos\PCOM\cvidistkit.PCOM_1" relOutputLocation="cvidistkit.PCOM_1" outputLocationWithVars="d:\Proyectos\PCOM\cvidistkit.%name_1" relOutputLocationWithVars="cvidistkit.%name_1" upgradeBehavior="1" autoIncrement="true" version="1.0.3">
			<arp company="PACOCO" companyURL="https://patriciocoronadocollado.000webhostapp.com/" supportURL="https://github.com/PatricioCoronado/PCOM" contact="patriciocoronadocollado@gmail.com" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="English" showPaths="true" readMe="" license="">
			<dlgstrings welcomeTitle="PCOM" welcomeText=""/></userinterface>
		<dirs appDirID="101">
			<installDir name="[Program Data]" dirID="27" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="PCOM" dirID="100" parentID="7" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="PCOM" dirID="101" parentID="2" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="d:\Proyectos\PCOM\cvibuild.PCOM\Release\PCOM.exe" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="d:\Proyectos\PCOM\copyright.rtf" relSourcePath="copyright.rtf" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<fileGroups>
			<projectOutput targetType="0" dirID="101" projectID="0">
				<fileID>0</fileID></projectOutput>
			<projectDependencies dirID="101" projectID="0"/></fileGroups>
		<shortcuts>
			<shortcut name="PCOM" targetFileID="0" destDirID="100" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<products/>
		<runtimeEngine cvirte="true" instrsup="true" lvrt="true" analysis="true" netvarsup="true" dotnetsup="true" activeXsup="true" rtutilsup="true" installToAppDir="false"/><sxsRuntimeEngine>
			<selected>false</selected>
			<doNotAutoSelect>false</doNotAutoSelect></sxsRuntimeEngine>
		<advanced mediaSize="650">
			<launchConditions>
				<condition>MINOS_WINXP_SP0</condition>
			</launchConditions>
			<includeConfigProducts>true</includeConfigProducts>
			<maxImportVisible>silent</maxImportVisible>
			<maxImportMode>merge</maxImportMode>
			<custMsgFlag>false</custMsgFlag>
			<custMsgPath>c:\program files (x86)\national instruments\cvi2012\bin\msgrte.txt</custMsgPath>
			<signExe>false</signExe>
			<certificate></certificate>
			<signTimeURL></signTimeURL>
			<signDescURL></signDescURL></advanced>
		<Projects NumProjects="1">
			<Project000 ProjectID="0" ProjectAbsolutePath="d:\Proyectos\PCOM\PCOM.prj" ProjectRelativePath="PCOM.prj"/></Projects>
		<buildData progressBarRate="1.428180943498891">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.202991249999942</ProductsAdded>
				<DPConfigured>2.203067249999936</DPConfigured>
				<DPMergeModulesAdded>3.162993625000015</DPMergeModulesAdded>
				<DPClosed>7.175491750000035</DPClosed>
				<DistributionsCopied>8.331771874999955</DistributionsCopied>
				<End>70.019138999999996</End></progressTimes></buildData>
	</msi>
</distribution>
