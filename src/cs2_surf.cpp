/* System */
#include <filesystem>
#include <fstream>
#include <string>

/* Third Party */
#include <nlohmann/json.hpp>
#include <sqlite/sqlite3.h>

/* Project */
#include "cs2_surf.h"

cs2_surf::CS2Surf g_CS2Surf;

PLUGIN_EXPOSE(cs2_surf::CS2Surf, g_CS2Surf);
bool cs2_surf::CS2Surf::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late) {
    PLUGIN_SAVEVARS();

    // Hook into IMetamodListener Events
    g_SMAPI->AddListener(this, this);

    META_CONPRINTF("cs2_surf::CS2Surf::Load() Called.\n");

    // Get needed paths
    std::filesystem::path cwd = std::filesystem::current_path();
    std::filesystem::path baseDir = ismm->GetBaseDir();
    std::filesystem::path pluginDir = baseDir / "addons" / GetName();
    std::filesystem::path settingsCfgPath = pluginDir / "configs/settings.json";
    std::filesystem::path databasesCfgPath = pluginDir / "configs/databases.json";

    // Open each json file
    std::ifstream settingsCfgFile(settingsCfgPath.string());
    nlohmann::json settingsCfgJson;
    settingsCfgFile >> settingsCfgJson;

    std::ifstream databasesCfgFile(databasesCfgPath.string());
    nlohmann::json databasesCfgJson;
    databasesCfgFile >> databasesCfgJson;

    // Get the type of database being used
    std::string databaseCfgType = settingsCfgJson["database_type"];

    // Get the information for the database
    std::string databaseCfgPath = databasesCfgJson[databaseCfgType]["path"];
    std::string databaseCfgName = databasesCfgJson[databaseCfgType]["name"];
    std::string databaseCfgSchema = databasesCfgJson[databaseCfgType]["schema"];

    // Construct the path to the database file.
    std::filesystem::path databasePath = pluginDir / databaseCfgPath / databaseCfgName;

    META_CONPRINTF("Current Working Directory: %s\n", cwd.lexically_normal().string().c_str());
    META_CONPRINTF("Plugin Directory: %s\n", pluginDir.lexically_normal().string().c_str());
    META_CONPRINTF("Settings Config Path: %s\n", settingsCfgPath.lexically_normal().string().c_str());
    META_CONPRINTF("Databases Config Path: %s\n", databasesCfgPath.lexically_normal().string().c_str());
    META_CONPRINTF("Database Path: %s\n", databasePath.lexically_normal().string().c_str());

    return true;
}

bool cs2_surf::CS2Surf::Unload(char *error, size_t maxlen) {
    META_CONPRINTF("cs2_surf::CS2Surf::Unload() Called.\n");
    return true;
}

void cs2_surf::CS2Surf::OnLevelInit(char const *pMapName, char const *pMapEntities, char const *pOldLevel,
                                    char const *pLandmarkName, bool loadGame, bool background) {
    META_CONPRINTF("cs2_surf::CS2Surf::OnLevelInit() called with map \"%s\".\n", pMapName);
}

void cs2_surf::CS2Surf::OnLevelShutdown() { META_CONPRINTF("cs2_surf::CS2Surf::OnLevelShutdown() called.\n"); }

const char *cs2_surf::CS2Surf::GetAuthor() { return "CCarrMcMahon"; }

const char *cs2_surf::CS2Surf::GetName() { return "cs2-surf"; }

const char *cs2_surf::CS2Surf::GetDescription() { return "An open source plugin for surfing in CS2."; }

const char *cs2_surf::CS2Surf::GetURL() { return "N/A"; }

const char *cs2_surf::CS2Surf::GetLicense() { return "GNU GENERAL PUBLIC LICENSE"; }

const char *cs2_surf::CS2Surf::GetVersion() { return "v0.0.1-alpha"; }

const char *cs2_surf::CS2Surf::GetDate() { return __DATE__; }

const char *cs2_surf::CS2Surf::GetLogTag() { return "cs2-surf"; }
