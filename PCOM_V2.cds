<distribution version="12.0.1" name="PCOM" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{C12E1943-6A66-4837-A0A4-0350C01D6A14}">
		<general appName="PCOM" outputLocation="d:\PCOM_con_leer_buffer" outputLocationWithVars="d:\PCOM_con_leer_buffer" upgradeBehavior="1" autoIncrement="true" version="1.0.0">
			<arp company="PACOCO" companyURL="https://patriciocoronadocollado.000webhostapp.com/" supportURL="https://github.com/PatricioCoronado/PCOM" contact="patricio.coronado@uam.es" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="English" showPaths="true" readMe="" license="">
			<dlgstrings welcomeTitle="PCOM" welcomeText=""/></userinterface>
		<dirs appDirID="101">
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="PCOM" dirID="100" parentID="7" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="PCOM" dirID="101" parentID="2" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="f:\PCOM\LabWindowsCVI\cvibuild.PCOM\Release\PCOM.exe" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="d:\Proyectos\PCOM\copyright.rtf" relSourcePath="copyright.rtf" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<shortcuts>
			<shortcut name="PCOM" targetFileID="0" destDirID="100" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<products/>
		<runtimeEngine cvirte="true" instrsup="true" lvrt="true" analysis="true" netvarsup="true" dotnetsup="true" activeXsup="true" rtutilsup="true" installToAppDir="false"/><sxsRuntimeEngine>
			<selected>false</selected>
			<doNotAutoSelect>false</doNotAutoSelect></sxsRuntimeEngine>
		<advanced mediaSize="650">
			<launchConditions>
				<condition>MINOS_WINXP</condition>
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
			<Project000 ProjectID="0" ProjectAbsolutePath="d:\Proyectos\PCOM\PCOM.prj"/></Projects>
		<buildData progressBarRate="0.561435516506219">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.263551875000039</ProductsAdded>
				<DPConfigured>2.819069624999898</DPConfigured>
				<DPMergeModulesAdded>3.718314750000079</DPMergeModulesAdded>
				<DPClosed>9.979077875000066</DPClosed>
				<DistributionsCopied>11.354066874999795</DistributionsCopied>
				<End>178.114844999999890</End></progressTimes></buildData>
	</msi>
</distribution>
