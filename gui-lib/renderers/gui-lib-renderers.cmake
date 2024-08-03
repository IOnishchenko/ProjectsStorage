
set(GUI_RENDERERS_SRCS
	"${project_dir}/gui-lib/renderers/ControlRenderer.cpp"
	"${project_dir}/gui-lib/renderers/GElementDecoderRGB565.cpp"
	"${project_dir}/gui-lib/renderers/iterators/BitDataIterrator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/L4A4CompresedDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/L4A4DataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/L8A8CompresedDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/L8A8DataIterator.cpp"
)

set(GUI_RENDERERS_INCS
	"${project_dir}/gui-lib/renderers"
	"${project_dir}/gui-lib/renderers/iterators"
)