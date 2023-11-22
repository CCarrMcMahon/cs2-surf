import sys
from ambuild2 import run


API_VERSION = "2.2.4"

PLUGIN_NAME = "cs2-surf"
PLUGIN_ALIAS = ""
MMS_PATH = "metamod-source"
HL2SDK_PATH = "hl2sdk-cs2"


if not run.HasAPI(API_VERSION):
    raise ImportError(f"This plugin requires AMBuild version {API_VERSION} or similar to be installed.")

builder = run.BuildParser(sourcePath=sys.path[0], api=API_VERSION)
builder.options.add_argument(
    "--name",
    type=str,
    default=PLUGIN_NAME,
    help="The overall name of the plugin.",
)
builder.options.add_argument(
    "--alias",
    type=str,
    default=PLUGIN_ALIAS,
    help="An alias for the name of the plugin.",
)
builder.options.add_argument(
    "--mms_path",
    type=str,
    default=MMS_PATH,
    help="The path to the Metamod:Source directory.",
)
builder.options.add_argument(
    "--hl2sdk_path",
    type=str,
    default=HL2SDK_PATH,
    help="The path to the HL2SDK directory.",
)
builder.Configure()
