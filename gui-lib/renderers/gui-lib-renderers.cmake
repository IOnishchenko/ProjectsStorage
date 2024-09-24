
set(GUI_RENDERERS_SRCS
	"${lib_source_files_dir}/gui-lib/renderers/ControlRenderer.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/GElementDecoderRGB565.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/A4CompressedDataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/A4DataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/A8CompressedDataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/A8DataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/AL44DataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/Base4BitsCompressedDataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/Base4BitsDataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/Base8BitsCompressedDataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/Base8BitsDataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/BitDataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/L4CompressedDataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/L4DataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/L8CompressedDataIterator.cpp"
	"${lib_source_files_dir}/gui-lib/renderers/iterators/L8DataIterator.cpp"
)

set(GUI_RENDERERS_INCS
	"${lib_source_files_dir}/gui-lib/renderers"
	"${lib_source_files_dir}/gui-lib/renderers/iterators"
)