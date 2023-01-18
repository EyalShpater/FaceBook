#ifndef __VIDEO_STATUS_H
#define __VIDEO_STATUS_H

#include "status.h"

#include <iostream>
#include <string>

class VideoStatus :public Status
{
    std::string filePath;
public:
    VideoStatus(const std::string& text, const std::string& filePath) noexcept(false);
    VideoStatus(std::ifstream& inFile);

    virtual void toOs(std::ostream& os) const override;

    virtual void save(std::ofstream& outFile) const override;

    virtual bool operator==(const Status& other) const override;
    virtual bool operator!=(const Status& other) const override;

private:
    VideoStatus(const VideoStatus& other);
    VideoStatus& operator=(const VideoStatus&);
};

#endif //__VIDEO_STATUS_H