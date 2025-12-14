#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <vector>
#include <map>
#include <iostream>

struct Location
{
    std::string path;
    std::map<std::string, std::string> directives;
};

struct Config
{
    int host;
    std::string port;
    std::map<std::string, std::string> pages;
    std::vector<Location> locations;
};
std::vector<Config> parserConfig(const std::string& filename);
void printConfig(const Config& cfg);

#endif


//server
//{
//    listen 127.0.0.1:4243;
//    error_page 404 ./example/404.html;
//    max_body_size 2097152; # 2 MiB

//    # Define a route for the static website
//    location /
//	{
//        allow_methods GET;
//        root ./example/static_website;
//        index index.html;
//    }

//    # Define a route for the Doxygen documentation
//    location /doc
//    {
//        allow_methods GET;
//        root ./doc/html;
//        index index.html;
//    }
//}