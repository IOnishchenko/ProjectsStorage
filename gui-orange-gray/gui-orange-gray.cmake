include("${root_dir}/gui-orange-gray/controls-src/gui-orange-gray-controls.cmake")
include("${root_dir}/gui-orange-gray/fonts-src/gui-orange-gray-fonts.cmake")
include("${root_dir}/gui-orange-gray/pictures-src/gui-orange-gray-pictures.cmake")

set(GUI_ORANGE_GRAY_SRCS
	"${GUI_ORANGE_GRAY_CONTROLS_SRCS}"
	"${GUI_ORANGE_GRAY_FONTS_SRCS}"
	"${GUI_ORANGE_GRAY_PICTURES_SRCS}"
)

set(GUI_ORANGE_GRAY_INCS
	"${lib_source_files_dir}/gui-orange-gray"
	"${GUI_ORANGE_GRAY_CONTROLS_INCS}"
	"${GUI_ORANGE_GRAY_FONTS_INCS}"
	"${GUI_ORANGE_GRAY_PICTURES_INCS}"
)