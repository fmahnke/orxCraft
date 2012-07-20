##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Linux_Release
ProjectName            :=OrxCraft
ConfigurationName      :=Linux_Release
IntermediateDirectory  :=../../LinuxRelease
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/konrad/Projects/OrxCraft/build/codelite/OrxCraft"
ProjectPath            := "/home/konrad/Projects/OrxCraft/build/codelite/OrxCraft"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Konrad Klimaszewski
Date                   :=20.07.2012
CodeLitePath           :="/home/konrad/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="/home/konrad/Projects/OrxCraft/build/codelite/OrxCraft/OrxCraft.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
CmpOptions             :=-I../../../include -O2 -Wall $(Preprocessors)
C_CmpOptions           :=-I../../../include -O2 -Wall $(Preprocessors)
LinkOptions            := -Wl,-rpath=lib/orx -Wl,-rpath=lib/cegui 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(CEGUI_DIR)/cegui/include $(IncludeSwitch)$(SCROLL_DIR)/include/Scroll/ $(IncludeSwitch)$(ORX_DIR)/code/include $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)CEGUIBase $(LibrarySwitch)CEGUIOpenGLRenderer $(LibrarySwitch)orx 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(ORX_DIR)/code/lib/dynamic $(LibraryPathSwitch)$(CEGUI_DIR)/lib 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
ORX_DIR:=$(HOME)/Projects/orx
CEGUI_DIR:=$(HOME)/Projects/CEGUI-0.7.7
SCROLL_DIR:=$(HOME)/Projects/scroll
Objects=$(IntermediateDirectory)/src_CEGUICheckbox$(ObjectSuffix) $(IntermediateDirectory)/src_CEGUICombobox$(ObjectSuffix) $(IntermediateDirectory)/src_CEGUIEditbox$(ObjectSuffix) $(IntermediateDirectory)/src_CEGUIListbox$(ObjectSuffix) $(IntermediateDirectory)/src_CEGUIPushButton$(ObjectSuffix) $(IntermediateDirectory)/src_FXSlotEditorWindow$(ObjectSuffix) $(IntermediateDirectory)/src_InfoWindow$(ObjectSuffix) $(IntermediateDirectory)/src_ObjectEditor$(ObjectSuffix) $(IntermediateDirectory)/src_orx_config_util$(ObjectSuffix) $(IntermediateDirectory)/src_orxcraft$(ObjectSuffix) \
	$(IntermediateDirectory)/src_RocketDataSource$(ObjectSuffix) $(IntermediateDirectory)/src_RocketFileInterface$(ObjectSuffix) $(IntermediateDirectory)/src_RocketListbox$(ObjectSuffix) $(IntermediateDirectory)/src_RocketListener$(ObjectSuffix) $(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(ObjectSuffix) $(IntermediateDirectory)/src_ScrollGUICEGUI$(ObjectSuffix) $(IntermediateDirectory)/src_ScrollGUIRocket$(ObjectSuffix) $(IntermediateDirectory)/src_WidgetManagerCEGUI$(ObjectSuffix) $(IntermediateDirectory)/src_WidgetManagerRocket$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

PostBuild:
	@echo Executing Post Build commands ...
	ln -sf ../../data $(IntermediateDirectory)
	ln -sf data/OrxCraft.ini $(IntermediateDirectory)/OrxCraft.ini
	mkdir -p $(IntermediateDirectory)/lib/orx
	mkdir -p $(IntermediateDirectory)/lib/cegui
	ln -sf $(ORX_DIR)/code/lib/dynamic/* $(IntermediateDirectory)/lib/orx
	ln -sf $(CEGUI_DIR)/lib/* $(IntermediateDirectory)/lib/cegui
	@echo Done

$(IntermediateDirectory)/.d:
	@test -d ../../LinuxRelease || $(MakeDirCommand) ../../LinuxRelease

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_CEGUICheckbox$(ObjectSuffix): ../../../src/CEGUICheckbox.cpp $(IntermediateDirectory)/src_CEGUICheckbox$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/CEGUICheckbox.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_CEGUICheckbox$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CEGUICheckbox$(DependSuffix): ../../../src/CEGUICheckbox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CEGUICheckbox$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CEGUICheckbox$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/CEGUICheckbox.cpp"

$(IntermediateDirectory)/src_CEGUICheckbox$(PreprocessSuffix): ../../../src/CEGUICheckbox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CEGUICheckbox$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/CEGUICheckbox.cpp"

$(IntermediateDirectory)/src_CEGUICombobox$(ObjectSuffix): ../../../src/CEGUICombobox.cpp $(IntermediateDirectory)/src_CEGUICombobox$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/CEGUICombobox.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_CEGUICombobox$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CEGUICombobox$(DependSuffix): ../../../src/CEGUICombobox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CEGUICombobox$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CEGUICombobox$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/CEGUICombobox.cpp"

$(IntermediateDirectory)/src_CEGUICombobox$(PreprocessSuffix): ../../../src/CEGUICombobox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CEGUICombobox$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/CEGUICombobox.cpp"

$(IntermediateDirectory)/src_CEGUIEditbox$(ObjectSuffix): ../../../src/CEGUIEditbox.cpp $(IntermediateDirectory)/src_CEGUIEditbox$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/CEGUIEditbox.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_CEGUIEditbox$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CEGUIEditbox$(DependSuffix): ../../../src/CEGUIEditbox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CEGUIEditbox$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CEGUIEditbox$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/CEGUIEditbox.cpp"

$(IntermediateDirectory)/src_CEGUIEditbox$(PreprocessSuffix): ../../../src/CEGUIEditbox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CEGUIEditbox$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/CEGUIEditbox.cpp"

$(IntermediateDirectory)/src_CEGUIListbox$(ObjectSuffix): ../../../src/CEGUIListbox.cpp $(IntermediateDirectory)/src_CEGUIListbox$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/CEGUIListbox.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_CEGUIListbox$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CEGUIListbox$(DependSuffix): ../../../src/CEGUIListbox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CEGUIListbox$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CEGUIListbox$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/CEGUIListbox.cpp"

$(IntermediateDirectory)/src_CEGUIListbox$(PreprocessSuffix): ../../../src/CEGUIListbox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CEGUIListbox$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/CEGUIListbox.cpp"

$(IntermediateDirectory)/src_CEGUIPushButton$(ObjectSuffix): ../../../src/CEGUIPushButton.cpp $(IntermediateDirectory)/src_CEGUIPushButton$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/CEGUIPushButton.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_CEGUIPushButton$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_CEGUIPushButton$(DependSuffix): ../../../src/CEGUIPushButton.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_CEGUIPushButton$(ObjectSuffix) -MF$(IntermediateDirectory)/src_CEGUIPushButton$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/CEGUIPushButton.cpp"

$(IntermediateDirectory)/src_CEGUIPushButton$(PreprocessSuffix): ../../../src/CEGUIPushButton.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_CEGUIPushButton$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/CEGUIPushButton.cpp"

$(IntermediateDirectory)/src_FXSlotEditorWindow$(ObjectSuffix): ../../../src/FXSlotEditorWindow.cpp $(IntermediateDirectory)/src_FXSlotEditorWindow$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/FXSlotEditorWindow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_FXSlotEditorWindow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_FXSlotEditorWindow$(DependSuffix): ../../../src/FXSlotEditorWindow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_FXSlotEditorWindow$(ObjectSuffix) -MF$(IntermediateDirectory)/src_FXSlotEditorWindow$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/FXSlotEditorWindow.cpp"

$(IntermediateDirectory)/src_FXSlotEditorWindow$(PreprocessSuffix): ../../../src/FXSlotEditorWindow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_FXSlotEditorWindow$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/FXSlotEditorWindow.cpp"

$(IntermediateDirectory)/src_InfoWindow$(ObjectSuffix): ../../../src/InfoWindow.cpp $(IntermediateDirectory)/src_InfoWindow$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/InfoWindow.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_InfoWindow$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_InfoWindow$(DependSuffix): ../../../src/InfoWindow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_InfoWindow$(ObjectSuffix) -MF$(IntermediateDirectory)/src_InfoWindow$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/InfoWindow.cpp"

$(IntermediateDirectory)/src_InfoWindow$(PreprocessSuffix): ../../../src/InfoWindow.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_InfoWindow$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/InfoWindow.cpp"

$(IntermediateDirectory)/src_ObjectEditor$(ObjectSuffix): ../../../src/ObjectEditor.cpp $(IntermediateDirectory)/src_ObjectEditor$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/ObjectEditor.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_ObjectEditor$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ObjectEditor$(DependSuffix): ../../../src/ObjectEditor.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ObjectEditor$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ObjectEditor$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/ObjectEditor.cpp"

$(IntermediateDirectory)/src_ObjectEditor$(PreprocessSuffix): ../../../src/ObjectEditor.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ObjectEditor$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/ObjectEditor.cpp"

$(IntermediateDirectory)/src_orx_config_util$(ObjectSuffix): ../../../src/orx_config_util.cpp $(IntermediateDirectory)/src_orx_config_util$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/orx_config_util.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_orx_config_util$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_orx_config_util$(DependSuffix): ../../../src/orx_config_util.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_orx_config_util$(ObjectSuffix) -MF$(IntermediateDirectory)/src_orx_config_util$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/orx_config_util.cpp"

$(IntermediateDirectory)/src_orx_config_util$(PreprocessSuffix): ../../../src/orx_config_util.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_orx_config_util$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/orx_config_util.cpp"

$(IntermediateDirectory)/src_orxcraft$(ObjectSuffix): ../../../src/orxcraft.cpp $(IntermediateDirectory)/src_orxcraft$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/orxcraft.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_orxcraft$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_orxcraft$(DependSuffix): ../../../src/orxcraft.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_orxcraft$(ObjectSuffix) -MF$(IntermediateDirectory)/src_orxcraft$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/orxcraft.cpp"

$(IntermediateDirectory)/src_orxcraft$(PreprocessSuffix): ../../../src/orxcraft.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_orxcraft$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/orxcraft.cpp"

$(IntermediateDirectory)/src_RocketDataSource$(ObjectSuffix): ../../../src/RocketDataSource.cpp $(IntermediateDirectory)/src_RocketDataSource$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/RocketDataSource.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_RocketDataSource$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_RocketDataSource$(DependSuffix): ../../../src/RocketDataSource.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_RocketDataSource$(ObjectSuffix) -MF$(IntermediateDirectory)/src_RocketDataSource$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/RocketDataSource.cpp"

$(IntermediateDirectory)/src_RocketDataSource$(PreprocessSuffix): ../../../src/RocketDataSource.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_RocketDataSource$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/RocketDataSource.cpp"

$(IntermediateDirectory)/src_RocketFileInterface$(ObjectSuffix): ../../../src/RocketFileInterface.cpp $(IntermediateDirectory)/src_RocketFileInterface$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/RocketFileInterface.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_RocketFileInterface$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_RocketFileInterface$(DependSuffix): ../../../src/RocketFileInterface.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_RocketFileInterface$(ObjectSuffix) -MF$(IntermediateDirectory)/src_RocketFileInterface$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/RocketFileInterface.cpp"

$(IntermediateDirectory)/src_RocketFileInterface$(PreprocessSuffix): ../../../src/RocketFileInterface.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_RocketFileInterface$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/RocketFileInterface.cpp"

$(IntermediateDirectory)/src_RocketListbox$(ObjectSuffix): ../../../src/RocketListbox.cpp $(IntermediateDirectory)/src_RocketListbox$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/RocketListbox.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_RocketListbox$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_RocketListbox$(DependSuffix): ../../../src/RocketListbox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_RocketListbox$(ObjectSuffix) -MF$(IntermediateDirectory)/src_RocketListbox$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/RocketListbox.cpp"

$(IntermediateDirectory)/src_RocketListbox$(PreprocessSuffix): ../../../src/RocketListbox.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_RocketListbox$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/RocketListbox.cpp"

$(IntermediateDirectory)/src_RocketListener$(ObjectSuffix): ../../../src/RocketListener.cpp $(IntermediateDirectory)/src_RocketListener$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/RocketListener.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_RocketListener$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_RocketListener$(DependSuffix): ../../../src/RocketListener.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_RocketListener$(ObjectSuffix) -MF$(IntermediateDirectory)/src_RocketListener$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/RocketListener.cpp"

$(IntermediateDirectory)/src_RocketListener$(PreprocessSuffix): ../../../src/RocketListener.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_RocketListener$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/RocketListener.cpp"

$(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(ObjectSuffix): ../../../src/RocketRenderInterfaceOrx.cpp $(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/RocketRenderInterfaceOrx.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(DependSuffix): ../../../src/RocketRenderInterfaceOrx.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(ObjectSuffix) -MF$(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/RocketRenderInterfaceOrx.cpp"

$(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(PreprocessSuffix): ../../../src/RocketRenderInterfaceOrx.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/RocketRenderInterfaceOrx.cpp"

$(IntermediateDirectory)/src_ScrollGUICEGUI$(ObjectSuffix): ../../../src/ScrollGUICEGUI.cpp $(IntermediateDirectory)/src_ScrollGUICEGUI$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/ScrollGUICEGUI.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_ScrollGUICEGUI$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ScrollGUICEGUI$(DependSuffix): ../../../src/ScrollGUICEGUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ScrollGUICEGUI$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ScrollGUICEGUI$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/ScrollGUICEGUI.cpp"

$(IntermediateDirectory)/src_ScrollGUICEGUI$(PreprocessSuffix): ../../../src/ScrollGUICEGUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ScrollGUICEGUI$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/ScrollGUICEGUI.cpp"

$(IntermediateDirectory)/src_ScrollGUIRocket$(ObjectSuffix): ../../../src/ScrollGUIRocket.cpp $(IntermediateDirectory)/src_ScrollGUIRocket$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/ScrollGUIRocket.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_ScrollGUIRocket$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ScrollGUIRocket$(DependSuffix): ../../../src/ScrollGUIRocket.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ScrollGUIRocket$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ScrollGUIRocket$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/ScrollGUIRocket.cpp"

$(IntermediateDirectory)/src_ScrollGUIRocket$(PreprocessSuffix): ../../../src/ScrollGUIRocket.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ScrollGUIRocket$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/ScrollGUIRocket.cpp"

$(IntermediateDirectory)/src_WidgetManagerCEGUI$(ObjectSuffix): ../../../src/WidgetManagerCEGUI.cpp $(IntermediateDirectory)/src_WidgetManagerCEGUI$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/WidgetManagerCEGUI.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_WidgetManagerCEGUI$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_WidgetManagerCEGUI$(DependSuffix): ../../../src/WidgetManagerCEGUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_WidgetManagerCEGUI$(ObjectSuffix) -MF$(IntermediateDirectory)/src_WidgetManagerCEGUI$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/WidgetManagerCEGUI.cpp"

$(IntermediateDirectory)/src_WidgetManagerCEGUI$(PreprocessSuffix): ../../../src/WidgetManagerCEGUI.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_WidgetManagerCEGUI$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/WidgetManagerCEGUI.cpp"

$(IntermediateDirectory)/src_WidgetManagerRocket$(ObjectSuffix): ../../../src/WidgetManagerRocket.cpp $(IntermediateDirectory)/src_WidgetManagerRocket$(DependSuffix)
	$(CompilerName) $(IncludePCH) $(SourceSwitch) "/home/konrad/Projects/OrxCraft/src/WidgetManagerRocket.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/src_WidgetManagerRocket$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_WidgetManagerRocket$(DependSuffix): ../../../src/WidgetManagerRocket.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_WidgetManagerRocket$(ObjectSuffix) -MF$(IntermediateDirectory)/src_WidgetManagerRocket$(DependSuffix) -MM "/home/konrad/Projects/OrxCraft/src/WidgetManagerRocket.cpp"

$(IntermediateDirectory)/src_WidgetManagerRocket$(PreprocessSuffix): ../../../src/WidgetManagerRocket.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_WidgetManagerRocket$(PreprocessSuffix) "/home/konrad/Projects/OrxCraft/src/WidgetManagerRocket.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/src_CEGUICheckbox$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUICheckbox$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUICheckbox$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUICombobox$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUICombobox$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUICombobox$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUIEditbox$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUIEditbox$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUIEditbox$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUIListbox$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUIListbox$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUIListbox$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUIPushButton$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUIPushButton$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_CEGUIPushButton$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_FXSlotEditorWindow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_FXSlotEditorWindow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_FXSlotEditorWindow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_InfoWindow$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_InfoWindow$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_InfoWindow$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_ObjectEditor$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_ObjectEditor$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_ObjectEditor$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_orx_config_util$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_orx_config_util$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_orx_config_util$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_orxcraft$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_orxcraft$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_orxcraft$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketDataSource$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketDataSource$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketDataSource$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketFileInterface$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketFileInterface$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketFileInterface$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketListbox$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketListbox$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketListbox$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketListener$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketListener$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketListener$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_RocketRenderInterfaceOrx$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_ScrollGUICEGUI$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_ScrollGUICEGUI$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_ScrollGUICEGUI$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_ScrollGUIRocket$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_ScrollGUIRocket$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_ScrollGUIRocket$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_WidgetManagerCEGUI$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_WidgetManagerCEGUI$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_WidgetManagerCEGUI$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/src_WidgetManagerRocket$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/src_WidgetManagerRocket$(DependSuffix)
	$(RM) $(IntermediateDirectory)/src_WidgetManagerRocket$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "/home/konrad/Projects/OrxCraft/build/codelite/OrxCraft/.build-linux_release/OrxCraft"


