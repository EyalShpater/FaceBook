#ifndef __VIDEO_STATUS_H
#define __VIDEO_STATUS_H

#include "status.h"

#include <iostream>
#include <string>

class VideoStatus :public Status
{
    std::string filePath;
public:
    VideoStatus(const std::string& text) noexcept(false)
        : filePath(filePath), Status(eColor::COLORS, eSoftware::PLAYBACK)
    {
        if (text == "") throw EmptyTextException();
    }

    virtual void toOs(std::ostream& os) const override;

    bool operator==(const VideoStatus& other)const;
    bool operator!=(const VideoStatus& other)const;

    virtual bool operator==(const Status& other) const override;
    virtual bool operator!=(const Status& other) const override;


private:
    VideoStatus(const VideoStatus& other);
    const VideoStatus& operator=(const VideoStatus&);
};

#endif //__VIDEO_STATUS_H