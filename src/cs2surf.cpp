/* System */
#include <string>
#include <filesystem>
#include <fstream>

/* Third Party */
#include <nlohmann/json.hpp>
#include <sqlite/sqlite3.h>

/* Project */
#include "cs2surf.h"

cs2surf::CS2Surf g_CS2Surf;

PLUGIN_EXPOSE(cs2surf::CS2Surf, g_CS2Surf);
bool cs2surf::CS2Surf::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late) {
    PLUGIN_SAVEVARS();

    // Hook into IMetamodListener Events
    g_SMAPI->AddListener(this, this);

    META_CONPRINTF("cs2surf::CS2Surf::Load() Called.\n");

    // Get needed paths
    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path baseDir = ismm->GetBaseDir();
    std::filesystem::path pluginDir = baseDir / "addons/cs2-surf";
    std::filesystem::path dbCfgFile = pluginDir / "configs/database.json";

    // Open the database.json file.
    std::ifstream configFile(dbCfgFile.string());

    // Parse the JSON file.
    nlohmann::json configJson;
    configFile >> configJson;

    // Get the database configuration.
    std::string dbType = configJson["database"]["type"];
    std::string dbName = configJson["database"][dbType]["name"];
    std::string dbPath = configJson["database"][dbType]["path"];

    // Construct the path to the database file.
    std::filesystem::path dbFilePath = pluginDir / dbPath / dbName;

    META_CONPRINTF("The path to the database cfg is: %s\n", dbCfgFile.lexically_normal().string().c_str());
    META_CONPRINTF("Current working directory: %s\n", cwd.lexically_normal().string().c_str());
    META_CONPRINTF("The path to the database is: %s\n", dbFilePath.lexically_normal().string().c_str());

    return true;
}

bool cs2surf::CS2Surf::Unload(char *error, size_t maxlen) {
    META_CONPRINTF("cs2surf::CS2Surf::Unload() Called.\n");
    return true;
}

void cs2surf::CS2Surf::OnLevelInit(char const *pMapName, char const *pMapEntities, char const *pOldLevel,
                                   char const *pLandmarkName, bool loadGame, bool background) {
    META_CONPRINTF("cs2surf::CS2Surf::OnLevelInit() called with map \"%s\".\n", pMapName);
}

void cs2surf::CS2Surf::OnLevelShutdown() { META_CONPRINTF("cs2surf::CS2Surf::OnLevelShutdown() called.\n"); }

const char *cs2surf::CS2Surf::GetAuthor() { return "CCarrMcMahon"; }

const char *cs2surf::CS2Surf::GetName() { return "cs2-surf"; }

const char *cs2surf::CS2Surf::GetDescription() { return "An open source plugin for surfing in CS2."; }

const char *cs2surf::CS2Surf::GetURL() { return "N/A"; }

const char *cs2surf::CS2Surf::GetLicense() { return "GNU GENERAL PUBLIC LICENSE"; }

const char *cs2surf::CS2Surf::GetVersion() { return "v0.0.1-alpha"; }

const char *cs2surf::CS2Surf::GetDate() { return __DATE__; }

const char *cs2surf::CS2Surf::GetLogTag() { return "[cs2-surf]"; }
