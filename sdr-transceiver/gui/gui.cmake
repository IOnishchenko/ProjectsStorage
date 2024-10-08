
set(SDR_GUI_SRCS
	"${project_dir}/gui/AudioView/InputSettingViews/AudioInputAGCSettingsView.cpp"
	"${project_dir}/gui/AudioView/InputSettingViews/AudioInputEqualizerView.cpp"
	"${project_dir}/gui/AudioView/InputSettingViews/AudioInputLevelsView.cpp"
	"${project_dir}/gui/AudioView/InputSettingViews/AudioInputManualSettingsView.cpp"
	"${project_dir}/gui/AudioView/InputSettingViews/AudioInputView.cpp"
	"${project_dir}/gui/AudioView/OutputSettingViews/AudioOutputEqualizerView.cpp"
	"${project_dir}/gui/AudioView/OutputSettingViews/AudioOutputLevelsView.cpp"
	"${project_dir}/gui/AudioView/OutputSettingViews/AudioOutputView.cpp"
	"${project_dir}/gui/AudioView/AudioView.cpp"

	"${project_dir}/gui/CustomUIControl/BandPassSliderWithLabel.cpp"
	"${project_dir}/gui/CustomUIControl/HPFSlider.cpp"
	"${project_dir}/gui/CustomUIControl/HPFSliderWithHeader.cpp"
	"${project_dir}/gui/CustomUIControl/LPFSlider.cpp"
	"${project_dir}/gui/CustomUIControl/LPFSliderWithHeader.cpp"
	"${project_dir}/gui/CustomUIControl/SliderWithHeader.cpp"

	"${project_dir}/gui/DialogViews/SelectModulationDialog.cpp"
	"${project_dir}/gui/DialogViews/SetFiltersDialog.cpp"
	"${project_dir}/gui/DialogViews/SetReceiverAGCDialog.cpp"
	"${project_dir}/gui/DialogViews/SetVolumeDialog.cpp"
	"${project_dir}/gui/DialogViews/SliderDialog.cpp"

	"${project_dir}/gui/DSPView/DSPAlgorithmView/DSPAGCView.cpp"
	"${project_dir}/gui/DSPView/DSPAlgorithmView/DSPAlgorithmView.cpp"
	"${project_dir}/gui/DSPView/DSPAlgorithmView/DSPAlgorithmViewBase.cpp"
	"${project_dir}/gui/DSPView/DSPAlgorithmView/DSPNoiseBlankerView.cpp"
	"${project_dir}/gui/DSPView/DSPAlgorithmView/DSPNoiseReductionView.cpp"
	"${project_dir}/gui/DSPView/DSPAlgorithmView/DSPNotchView.cpp"
	"${project_dir}/gui/DSPView/DSPAlgorithmView/DSPSquelchView.cpp"

	"${project_dir}/gui/DSPView/DSPModulationView/AMModulationView.cpp"
	"${project_dir}/gui/DSPView/DSPModulationView/CWModulationView.cpp"
	"${project_dir}/gui/DSPView/DSPModulationView/DSPModulationView.cpp"
	"${project_dir}/gui/DSPView/DSPModulationView/FMModulationView.cpp"
	"${project_dir}/gui/DSPView/DSPModulationView/ModulationViewBase.cpp"
	"${project_dir}/gui/DSPView/DSPModulationView/SSBModulationView.cpp"
	"${project_dir}/gui/DSPView/DSPView.cpp"

	"${project_dir}/gui/MainView/MainView.cpp"
	"${project_dir}/gui/MainView/SpectrumView/SpectrumView.cpp"
	"${project_dir}/gui/MainView/SpectrumView/SpectrumViewSettings.cpp"

	"${project_dir}/gui/RadioView/RadioView.cpp"
	"${project_dir}/gui/RadioView/ReceiverView.cpp"
	"${project_dir}/gui/RadioView/TransmitterSettingsView.cpp"
	"${project_dir}/gui/RadioView/TransmitterView.cpp"

	"${project_dir}/gui/dumy_picture_gui320x240.c"
	"${project_dir}/gui/GUIThread.cpp"
	"${project_dir}/gui/ScreenBase.cpp"
)

set(SDR_GUI_INCS
	"${project_dir}/gui/"
	"${project_dir}/gui/AudioView/"
	"${project_dir}/gui/AudioView/InputSettingViews/"
	"${project_dir}/gui/AudioView/OutputSettingViews/"
	"${project_dir}/gui/CustomUIControl/"
	"${project_dir}/gui/DialogViews/"
	"${project_dir}/gui/DSPView/"
	"${project_dir}/gui/DSPView/DSPAlgorithmView/"
	"${project_dir}/gui/DSPView/DSPModulationView/"
	"${project_dir}/gui/MainView/"
	"${project_dir}/gui/MainView/SpectrumView/"
	"${project_dir}/gui/RadioView/"
	"${project_dir}/gui/SettingsView/"
)