#include <IniReader.hpp>

IniReader::IniReader()
{
    //ctor
}

bool IniReader::open( std::string fileName )
{
   _fileInput.open(fileName.c_str());
    return  !_fileInput ? false : true;
}

IniReader* IniReader::selectSection( std::string section )
{

    ReadFile();
    std::string _buffer;
    size_t posInitialBuffer = _BufferData.find("["+section+"]");

    if (_BufferData.find("["+section+"]") == (std::string::npos))
    {
        return this;
    }
    else
    {
        _buffer = _BufferData.substr(posInitialBuffer);
        size_t posInitial = _buffer.find("["+section+"]");
        size_t posEnd = _buffer.find_first_of("[",posInitial+1);

        size_t sizeOfString = posEnd-posInitial;
        _dataSection = _buffer.substr(posInitial,sizeOfString );

        return this;
    }
}

std::string IniReader::getValueOf(std::string key)
{
    unsigned int pos ;
    pos  = _dataSection.find(key);

    if ((pos==std::string::npos) || (_dataSection == ""))
    {
        return "";
    }
    else
    {
        int posValue = (_dataSection.find_first_of("=",pos) + 2);
        int posEndValue = _dataSection.find_first_of(" ",posValue);
        size_t sizeOfString = posEndValue-posValue;

        std::string value = _dataSection.substr(posValue,sizeOfString);

        return value ;
    }
}


void IniReader::close()
{
    _fileInput.close();
}


void IniReader::ReadFile()
{
    while( !_fileInput.eof())
    {
        std::string _buffer;

       _fileInput >> _buffer;
       _BufferData += " " + std::string(_buffer);
    }
}

IniReader::~IniReader()
{
    //dtor
}