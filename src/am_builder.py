from ambuild2.frontend.v2_2.context import BuildContext


# Create am_builder for this context
context: BuildContext = builder
am_builder = plugin.create_am_builder(context, plugin.plugin_name, "Library")

# Add includes
includes = am_builder.parse_paths_str(["db"], verify_exists=True)
am_builder.compiler_add_attrs("includes", *includes)

# Add sources
am_builder.add_binary_sources(["cs2surf.cpp", "db\\sqlite3.c"])

# Add am_builder to plugin
plugin.add_am_builder(am_builder)
