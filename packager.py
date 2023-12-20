from pathlib import Path

from ambuild2.frontend.system import System
from ambuild2.frontend.v2_2.context import BuildContext
from ambuild2.nodetypes import Entry


context: BuildContext = builder
context.SetBuildFolder("package")

for node in plugin.nodes:
    binary: Entry = node.binary
    target: System = node.target

    # Save info about binary
    binary_path = Path(f"{context.buildPath}\\{binary.path}").resolve()
    binary_name = binary_path.name
    binary_stem = binary_path.stem
    binary_alias = binary_path.parent.parent.name

    # Don't resolve since we need a relative path
    addons_folder = Path("addons")
    plugin_folder = addons_folder.joinpath(binary_alias)
    metamod_folder = addons_folder.joinpath("metamod")

    # Create other necessary folders
    configs_folder = plugin_folder.joinpath("configs")
    logs_folder = plugin_folder.joinpath("logs")
    data_folder = plugin_folder.joinpath("data")

    # Create proper package path based on compiler target
    binary_folder = plugin_folder
    if target.arch == "x86_64":
        if target.platform == "windows":
            binary_folder = binary_folder.joinpath("bin\\win64")
    binary_file_path = binary_folder.joinpath(binary_name)

    # Create necessary folders for packaging
    binary_folder_entry = context.AddFolder(str(binary_folder))
    metamod_folder_entry = context.AddFolder(str(metamod_folder))
    configs_folder_entry = context.AddFolder(str(configs_folder))
    logs_folder_entry = context.AddFolder(str(logs_folder))
    data_folder_entry = context.AddFolder(str(data_folder))

    # Create vdf file
    vdf_path = Path(f"{context.buildPath}\\{binary_stem}.vdf").resolve()
    with open(vdf_path, "w", encoding="utf-8") as f:
        f.write('"Metamod Plugin"\n')
        f.write("{\n")
        f.write(f'\t"alias"\t"{binary_alias}"\n')
        f.write(f'\t"file"\t"{binary_file_path}"\n')
        f.write("}\n")

    # Copy generated files to correct location in package
    context.AddCopy(binary, binary_folder_entry)
    context.AddCopy(str(vdf_path), metamod_folder_entry)

    # Copy config files to correct location in package
    database_config_path = Path(f"{context.sourcePath}\\configs\\database.json").resolve()
    context.AddCopy(str(database_config_path), configs_folder_entry)
