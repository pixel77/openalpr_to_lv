<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="14008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Help" Type="Folder">
			<Item Name="ci32.png" Type="Document" URL="../Help/ci32.png"/>
			<Item Name="cpath.png" Type="Document" URL="../Help/cpath.png"/>
			<Item Name="cstr.png" Type="Document" URL="../Help/cstr.png"/>
			<Item Name="i2dstr.png" Type="Document" URL="../Help/i2dstr.png"/>
			<Item Name="istr.png" Type="Document" URL="../Help/istr.png"/>
			<Item Name="OpenALPR toLabVIEW Base application_Help.html" Type="Document" URL="../Help/OpenALPR toLabVIEW Base application_Help.html"/>
			<Item Name="OpenALPR-basec.png" Type="Document" URL="../Help/OpenALPR-basec.png"/>
			<Item Name="OpenALPR-basep.png" Type="Document" URL="../Help/OpenALPR-basep.png"/>
		</Item>
		<Item Name="LvDLL" Type="Folder" URL="../LvDLL">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="OpenALPR_LabVIEW" Type="Folder" URL="../OpenALPR_LabVIEW">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="testpics" Type="Folder" URL="../testpics">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="baseico.ico" Type="Document" URL="../baseico.ico"/>
		<Item Name="bsae-app.bmp" Type="Document" URL="../bsae-app.bmp"/>
		<Item Name="curiosity_érdekesség.txt" Type="Document" URL="../curiosity_érdekesség.txt"/>
		<Item Name="OpenALPR-base.vi" Type="VI" URL="../OpenALPR-base.vi"/>
		<Item Name="read me_eng.rtf" Type="Document" URL="../read me_eng.rtf"/>
		<Item Name="read me_hu.rtf" Type="Document" URL="../read me_hu.rtf"/>
		<Item Name="Dependencies" Type="Dependencies"/>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="Test app" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{3F5C7A02-69DE-4B3D-8E06-8F5143EB973F}</Property>
				<Property Name="App_INI_GUID" Type="Str">{95C1EBF1-2CD2-463D-92E1-834562478A58}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{A5D5BC7A-B73C-48E8-8AB3-91BC3464BA5D}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Test app</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{D96421ED-C375-4BD4-97A3-D67827F7C853}</Property>
				<Property Name="Bld_version.build" Type="Int">12</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">OpenALPR_LW.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/OpenALPR_LW.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/data</Property>
				<Property Name="Destination[2].destName" Type="Str">main</Property>
				<Property Name="Destination[2].path" Type="Path">../builds/NI_AB_PROJECTNAME</Property>
				<Property Name="Destination[3].destName" Type="Str">Help</Property>
				<Property Name="Destination[3].path" Type="Path">../builds/NI_AB_PROJECTNAME/Help</Property>
				<Property Name="Destination[4].destName" Type="Str">testpics</Property>
				<Property Name="Destination[4].path" Type="Path">../builds/NI_AB_PROJECTNAME/testpics</Property>
				<Property Name="Destination[5].destName" Type="Str">OpenALPR_LabVIEW</Property>
				<Property Name="Destination[5].path" Type="Path">../builds/NI_AB_PROJECTNAME/OpenALPR_LabVIEW</Property>
				<Property Name="DestinationCount" Type="Int">6</Property>
				<Property Name="Exe_iconItemID" Type="Ref">/My Computer/baseico.ico</Property>
				<Property Name="Source[0].destinationIndex" Type="Int">2</Property>
				<Property Name="Source[0].itemID" Type="Str">{48245574-DA69-4CFB-988B-751D7F6B0D56}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/OpenALPR-base.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="Source[2].Container.applyDestination" Type="Bool">true</Property>
				<Property Name="Source[2].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[2].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[2].destinationIndex" Type="Int">3</Property>
				<Property Name="Source[2].itemID" Type="Ref">/My Computer/Help</Property>
				<Property Name="Source[2].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[2].type" Type="Str">Container</Property>
				<Property Name="Source[3].Container.applyDestination" Type="Bool">true</Property>
				<Property Name="Source[3].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[3].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[3].destinationIndex" Type="Int">4</Property>
				<Property Name="Source[3].itemID" Type="Ref">/My Computer/testpics</Property>
				<Property Name="Source[3].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[3].type" Type="Str">Container</Property>
				<Property Name="Source[4].Container.applyDestination" Type="Bool">true</Property>
				<Property Name="Source[4].Container.applyInclusion" Type="Bool">true</Property>
				<Property Name="Source[4].Container.depDestIndex" Type="Int">0</Property>
				<Property Name="Source[4].destinationIndex" Type="Int">5</Property>
				<Property Name="Source[4].itemID" Type="Ref">/My Computer/OpenALPR_LabVIEW</Property>
				<Property Name="Source[4].sourceInclusion" Type="Str">Include</Property>
				<Property Name="Source[4].type" Type="Str">Container</Property>
				<Property Name="SourceCount" Type="Int">5</Property>
				<Property Name="TgtF_companyName" Type="Str">Huszár Gál Gimnázium</Property>
				<Property Name="TgtF_fileDescription" Type="Str">Test app</Property>
				<Property Name="TgtF_internalName" Type="Str">Test app</Property>
				<Property Name="TgtF_productName" Type="Str">Test app</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{5F15DEB9-8DCC-4D62-82F0-F85B366C8E06}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">OpenALPR_LW.exe</Property>
			</Item>
		</Item>
	</Item>
</Project>
