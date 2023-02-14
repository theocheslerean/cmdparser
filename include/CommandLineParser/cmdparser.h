#pragma once

#include <map>
#include <string>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>
#include <initializer_list>

namespace CommandLineParser {

class ValueObject;
class ArgumentsMap;

class CMDParser {
    private:
        std::shared_ptr<ArgumentsMap> argumentsMap;
    public:
        inline CMDParser(int argc, char** argv) {

            std::map<std::string, std::shared_ptr<ValueObject>> list;

            bool flag = true;

            for(int counter = 1; counter < argc; counter++) {
                std::string key = (std::string)argv[counter];
                if(key.at(0) != '-' || key.length() <= 1) {
                    throw std::runtime_error("Cannot parse key " + std::to_string(counter) + ": \"" + key + "\"");
                }
                if(key.at(0) == '-' && key.length() > 1) {
                    key = key.erase(0,1);
                    std::string value = (std::string)argv[++counter];
                    list.insert(std::pair<std::string,std::shared_ptr<ValueObject>>(key, std::make_shared<ValueObject>(value)));
                }
                else {
                    throw std::runtime_error("Key \"" + key + "\": does not math format \"-<name>\"");
                }
            }

            if(!flag) {
                throw std::runtime_error("Please provide missing arguments");
            }

            argumentsMap = std::make_shared<ArgumentsMap>(list);

        }

        ArgumentsMap& get_map() {
            return *argumentsMap;
        }

};

namespace ValueParser {
        inline void parse(const std::string& value, int& result) {
            try {
                result = stoi(value);
            }
            catch(const std::exception &e) {
                throw std::invalid_argument("Cannot parse argument \"" + value + "\" to <int> type");
            }
        }

        inline void parse(const std::string& value, unsigned int& result) {
            try {
                result = stoul(value);
            }
            catch(const std::exception &e) {
                throw std::invalid_argument("Cannot parse argument \"" + value + "\" to <unsigned int> type");
            }
        }

        inline void parse(const std::string& value, long& result) {
            try {
                result = stol(value);
            }
            catch(const std::exception &e) {
                throw std::invalid_argument("Cannot parse argument \"" + value + "\" to <long> type");
            }
        }

        inline void parse(const std::string& value, float& result) {
            try {
                result = stof(value);
            }
            catch(const std::exception &e) {
                throw std::invalid_argument("Cannot parse argument \"" + value + "\" to <float> type");
            }
        }

        inline void parse(const std::string& value, double& result) {
            try {
                result = stod(value);
            }
            catch(const std::exception &e) {
                throw std::invalid_argument("Cannot parse argument \"" + value + "\" to <double> type");
            }
        }

        inline void parse(const std::string& value, std::string& result) {
            try {
                result = value;
            }
            catch(const std::exception &e) {
                throw std::invalid_argument("Cannot parse argument \"" + value + "\" to <string> type");
            }
        }
};

class ValueObject {
    private:
        std::string _value;

    public:
        ValueObject(std::string value)
        : _value(std::move(value))
        {}

        const
        std::string&
        get_value() const
        {
        return _value;
        }

        template <typename T>
        T
        as() const
        {
        T result;
        ValueParser::parse(_value, result);
        return result;
        }
};

class ArgumentsMap {
    private:
        std::map<std::string, std::shared_ptr<ValueObject>> _list;
    public:
        ArgumentsMap(std::map<std::string, std::shared_ptr<ValueObject>>& list) : _list(list) {}

        const ValueObject& operator[](const std::string& key) {
            try {
                return *_list.at(key);
            }
            catch(const std::exception& e) {
                throw std::out_of_range("Key \"" + key + "\" not found");
            }
        }
        
        inline size_t size() {
            return _list.size();
        }

};





}



