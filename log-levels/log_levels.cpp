#include <string>

namespace log_line
{
  std::string message(std::string line)
  {
    int messageStartIndex = line.find(" ");
    std::string messageToReturn = line.substr(messageStartIndex + 1); // one for the space

    return messageToReturn;
  }

  std::string log_level(std::string line)
  {
    int lastIndex = line.find("]");
    std::string logLevelToReturn = line.substr(1, lastIndex - 1);
    // return the log level
    return logLevelToReturn;
  }

  std::string reformat(std::string line)
  {
    std::string message{log_line::message(line)};
    std::string log_level{log_line::log_level(line)};

    std::string reformattedString = message + " (" + log_level + ")";
    return reformattedString;
  }
} // namespace log_line
