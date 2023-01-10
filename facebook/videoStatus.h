#ifndef __VIDEO_STATUS_H
#define __VIDEO_STATUS_H

#include "status.h"

#include <iostream>
#include <string>

class VideoStatus :public Status
{
    std::string filePath;
public:
    VideoStatus(const std::string& text, const std::string& filePath) noexcept(false)
        : filePath(filePath), Status(text, eColor::COLORS, eSoftware::PLAYBACK)
    {
        if (filePath == "") throw EmptyTextException();
    }

    virtual void toOs(std::ostream& os) const override;

    virtual bool operator==(const Status& other) const override;
    virtual bool operator!=(const Status& other) const override;

private:
    VideoStatus(const VideoStatus& other);
    const VideoStatus& operator=(const VideoStatus&);
};

#endif //__VIDEO_STATUS_H