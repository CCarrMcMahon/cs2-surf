am_builder = plugin.create_am_builder(builder, plugin.plugin_name, "Library")
am_builder.add_binary_sources(["sample_mm.cpp"])
plugin.add_am_builder(am_builder)
