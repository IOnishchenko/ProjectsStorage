
set(GUI_RENDERERS_SRCS
	"${project_dir}/gui-lib/renderers/ControlRenderer.cpp"
	"${project_dir}/gui-lib/renderers/GElementDecoderRGB565.cpp"
	"${project_dir}/gui-lib/renderers/iterators/A4CompressedDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/A4DataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/A8CompressedDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/A8DataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/AL44DataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/Base4BitsCompressedDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/Base4BitsDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/Base8BitsCompressedDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/Base8BitsDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/BitDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/L4CompressedDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/L4DataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/L8CompressedDataIterator.cpp"
	"${project_dir}/gui-lib/renderers/iterators/L8DataIterator.cpp"
)

set(GUI_RENDERERS_INCS
	"${project_dir}/gui-lib/renderers"
	"${project_dir}/gui-lib/renderers/iterators"
)