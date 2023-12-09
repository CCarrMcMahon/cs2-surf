from ambuild2.frontend.v2_2.context import BuildContext


# Create am_builder for this context
context: BuildContext = builder
am_builder = plugin.create_am_builder(context, plugin.plugin_name, "Library")

# Add sources
am_builder.add_binary_sources(["cs2surf.cpp"])

# Add am_builder to plugin
plugin.add_am_builder(am_builder)
