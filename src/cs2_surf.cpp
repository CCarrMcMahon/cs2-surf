#include "cs2_surf.h"

CS2Surf g_CS2Surf;

PLUGIN_EXPOSE(CS2Surf, g_CS2Surf);
bool CS2Surf::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
    PLUGIN_SAVEVARS();

    // Hook into IMetamodListener Events
    g_SMAPI->AddListener(this, this);

    META_CONPRINTF("CS2Surf::Load() Called.\n");
    return true;
}

bool CS2Surf::Unload(char *error, size_t maxlen)
{
    return true;
}

void CS2Surf::OnLevelInit(char const *pMapName,
                          char const *pMapEntities,
                          char const *pOldLevel,
                          char const *pLandmarkName,
                          bool loadGame,
                          bool background)
{
    META_CONPRINTF("CS2Surf::OnLevelInit() called with map \"%s\".\n", pMapName);
}

void CS2Surf::OnLevelShutdown()
{
    META_CONPRINTF("CS2Surf::OnLevelShutdown() called.\n");
}

const char *CS2Surf::GetAuthor()
{
    return "CCarrMcMahon";
}

const char *CS2Surf::GetName()
{
    return "cs2-surf";
}

const char *CS2Surf::GetDescription()
{
    return "An open source plugin for surfing in CS2.";
}

const char *CS2Surf::GetURL()
{
    return "N/A";
}

const char *CS2Surf::GetLicense()
{
    return "GNU GENERAL PUBLIC LICENSE";
}

const char *CS2Surf::GetVersion()
{
    return "v0.0.1-alpha";
}

const char *CS2Surf::GetDate()
{
    return __DATE__;
}

const char *CS2Surf::GetLogTag()
{
    return "CS2-SURF";
}
