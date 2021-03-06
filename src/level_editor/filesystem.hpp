#ifndef GRAAL_LEVEL_EDITOR_FILESYSTEM_HPP_
#define GRAAL_LEVEL_EDITOR_FILESYSTEM_HPP_

#include <map>
#include <boost/filesystem.hpp>
#include "preferences.hpp"

namespace Graal {
  namespace level_editor {
    class filesystem {
    public:
      typedef std::map<std::string, boost::filesystem::path> cache_type;

      filesystem(preferences& _prefs);

      void update_cache();
      // Updates the cache from FILENAMECACHE.txt
      bool update_cache_from_graal();
      
      bool get_path(const std::string& file_name, boost::filesystem::path& path_found);

      /*void load(const boost::filesystem::path& path);
      void save(const boost::filesystem::path& path);*/
    protected:
      cache_type m_cache;
      preferences& m_preferences;

      bool valid_dir();
    };
  }
}

#endif

