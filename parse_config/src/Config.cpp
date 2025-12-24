#include "../include/Config.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

static std::string trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t");
    size_t end   = s.find_last_not_of(" \t");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

static std::string removeSemicolon(std::string s)
{
    if (!s.empty() && s[s.size() - 1] == ';')
        s.erase(s.size() - 1);
    return s;
}

std::vector<Config> parserConfig(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("Failed to open config file");

	// multiple server
    std::vector<Config> servers;

	// single config file to lisetn
    Config currentServer;

	// single location, route
    Location currentLocation;

	// block is state or server
    enum State { NONE, SERVER, LOCATION };

	// init state
    State state = NONE;

    std::string line;
    while (std::getline(file, line))
    {
        // Remove comments
        size_t comment = line.find('#');
        if (comment != std::string::npos)
            line.erase(comment);

		// skip space and empty line
        line = trim(line);
        if (line.empty())
            continue;

        // (line == server) => {state = SERVER}
        if (line == "server")
        {
            state = SERVER;
			// create a struct with current block
            currentServer = Config();
            continue;
        }

		// skip single open curly bracket
        if (line == "{")
            continue;

        // block end have two state location or server
		// if (line == } ) then create location or server
        if (line == "}")
        {
            if (state == LOCATION)
            {
                currentServer.locations.push_back(currentLocation);
				// create new struct from location and change state
                currentLocation = Location();
                state = SERVER;
            }
            else if (state == SERVER)
            {
                servers.push_back(currentServer);
				// create new config server struct and change state
                currentServer = Config();
                state = NONE;
            }
            continue;
        }

        std::istringstream ss(line);

        // location block (line.find(location))=>{state = LOCATION}
        if (line.find("location") == 0)
        {
            std::string keyword, path; // location /doc
            ss >> keyword >> path;
            currentLocation = Location();
            currentLocation.path = path;
            state = LOCATION; // state is location
            continue;
        }

        // DIRECTIVES
		#pragma region // check which part should parser, in which state is?
        std::string key, value;
        ss >> key >> value;

		// remove ; from end
        value = removeSemicolon(value);

        if (state == SERVER)
        {
			// in server state has first line and rest
            if (key == "listen")
            {
                size_t pos = value.find(':');
                if (pos == std::string::npos)
                    throw std::runtime_error("Invalid listen directive");

                currentServer.host = atoi(value.substr(0, pos).c_str());
                currentServer.port = value.substr(pos + 1);
            }
            else
            {
                currentServer.pages[key] = value;
            }
        }
        else if (state == LOCATION)
        {
            currentLocation.directives[key] = value;
        }
		#pragma endregion
    }

    return servers;
}


void printConfig(const Config& cfg)
{
    std::cout << "===== SERVER =====\n";
    std::cout << "Host: " << cfg.host << "\n";
    std::cout << "Port: " << cfg.port << "\n";

    std::cout << "\n-- Server Directives --\n";
    for (std::map<std::string, std::string>::const_iterator it = cfg.pages.begin();
         it != cfg.pages.end(); ++it)
    {
        std::cout << it->first << " = " << it->second << "\n";
    }

    std::cout << "\n-- Locations --\n";
    for (size_t i = 0; i < cfg.locations.size(); ++i)
    {
        const Location& loc = cfg.locations[i];
        std::cout << "  Location: " << loc.path << "\n";

        for (std::map<std::string, std::string>::const_iterator it = loc.directives.begin();
             it != loc.directives.end(); ++it)
        {
            std::cout << "    " << it->first << " = " << it->second << "\n";
        }
    }

    std::cout << "=====================\n\n";
}
