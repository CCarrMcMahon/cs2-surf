#ifndef CS2_SURF_H_INCLUDED
#define CS2_SURF_H_INCLUDED

#include <ISmmPlugin.h>

class CS2Surf : public ISmmPlugin, public IMetamodListener
{
public: // ISmmPlugin (States)
    bool Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late) override;
    bool Unload(char *error, size_t maxlen) override;

public: // ISmmPlugin (Information)
    const char *GetAuthor() override;
    const char *GetName() override;
    const char *GetDescription() override;
    const char *GetURL() override;
    const char *GetLicense() override;
    const char *GetVersion() override;
    const char *GetDate() override;
    const char *GetLogTag() override;

public: // IMetamodListener (Events)
    void OnLevelInit(char const *pMapName,
                     char const *pMapEntities,
                     char const *pOldLevel,
                     char const *pLandmarkName,
                     bool loadGame,
                     bool background) override;
    void OnLevelShutdown() override;
};

extern CS2Surf g_CS2Surf;

PLUGIN_GLOBALVARS();

#endif // CS2_SURF_H_INCLUDED
