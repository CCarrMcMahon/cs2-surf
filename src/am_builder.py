from ambuild2.frontend.v2_2.context import BuildContext


# Create am_builder for this context
context: BuildContext = builder
am_builder = plugin.create_am_builder(context, plugin.plugin_name, "library")

# Add includes
include_paths = [
    f"{context.sourcePath}\\include",
    f"{context.sourcePath}\\thirdparty",
]
includes = am_builder.parse_paths_str(include_paths, verify_exists=True)
am_builder.compiler_add_attrs("includes", *includes)

# Add sources
source_paths = [f"{context.sourcePath}\\thirdparty\\sqlite\\sqlite3.c", "cs2_surf.cpp"]
sources = am_builder.parse_paths_str(source_paths, verify_exists=True)
am_builder.add_binary_sources(sources)

# Add am_builder to plugin
plugin.add_am_builder(am_builder)
