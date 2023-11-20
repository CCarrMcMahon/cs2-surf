import sys
from ambuild2 import run


API_VERSION = "2.2.4"
if not run.HasAPI(API_VERSION):
    raise ImportError(f"This plugin requires AMBuild version {API_VERSION} or similar to be installed.")

builder = run.BuildParser(sourcePath=sys.path[0], api=API_VERSION)
builder.options.add_argument(
    "--plugin_name",
    type=str,
    default="cs2-surf",
    help="The overall name of the plugin.",
)
builder.options.add_argument(
    "--plugin_alias",
    type=str,
    default="",
    help="An alias for the name of the plugin to appear in the metaplugins.ini file.",
)
builder.options.add_argument(
    "--debug",
    action="store_true",
    default=False,
    help="Include to enable debugging symbols.",
)
builder.options.add_argument(
    "--optimize",
    action="store_true",
    default=False,
    help="Include to enable compiler optimizations.",
)
builder.Configure()
