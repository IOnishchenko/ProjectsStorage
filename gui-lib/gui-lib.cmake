include("${root_dir}/gui-lib/gelements/gui-lib-gelements.cmake")
include("${root_dir}/gui-lib/controls/gui-lib-controls.cmake")
include("${root_dir}/gui-lib/renderers/gui-lib-renderers.cmake")
include("${root_dir}/gui-lib/events/gui-lib-events.cmake")

set(GUI_LIB_SRCS
	"${GUI_GELEMENTS_SRCS}"
	"${GUI_CONTROLS_SRCS}"
	"${GUI_RENDERERS_SRCS}"
	"${GUI_EVENTS_SRCS}"
)

set(GUI_LIB_INCS
	"${GUI_GELEMENTS_INCS}"
	"${GUI_CONTROLS_INCS}"
	"${GUI_RENDERERS_INCS}"
	"${GUI_EVENTS_INCS}"
	"${lib_source_files_dir}/gui-lib"
)