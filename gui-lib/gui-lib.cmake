include("${root_dir}/gui-lib/gelements/gui-lib-gelements.cmake")
include("${root_dir}/gui-lib/controls/gui-lib-controls.cmake")

set(GUI_LIB_SRCS
	"${GUI_GELEMENTS_SRCS}"
	"${GUI_CONTROLS_SRCS}"
)

set(GUI_LIB_DIRS
	"${GUI_GELEMENTS_INCS}"
	"${GUI_CONTROLS_INCS}"
)