API_VERSION = '2.2.4'

import sys
try:
    from ambuild2 import run
    if not run.HasAPI(API_VERSION):
        raise Exception()
except:
    sys.stderr.write('AMBuild {0} must be installed to build this project.\n'.format(API_VERSION))
    sys.stderr.write('http://www.alliedmods.net/ambuild\n')
    sys.exit(1)

builder = run.BuildParser(sourcePath=sys.path[0], api=API_VERSION)
builder.options.add_argument(
    "--plugin_name",
    type=str,
    default="",
    help="The overall name of the plugin.",
)
builder.options.add_argument(
    "--plugin_alias",
    type=str,
    default="",
    help="An alias used in metaplugins.ini for the name of the plugin.",
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
