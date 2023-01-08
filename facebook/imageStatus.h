#ifndef __IMAGE_STATUS_H
#define __IMAGE_STATUS_H

#include "status.h"

#include <iostream>
#include <string>

class ImageStatus :public Status
{
    std::string filePath;
public:
    ImageStatus(const std::string& filePath) noexcept(false)
        : filePath(filePath), Status(eColor::COLORS, eSoftware::PLAYBACK)
    {
        if (filePath == "") throw EmptyTextException();
    }

    virtual void toOs(std::ostream& os) const override;

    bool operator==(const ImageStatus& other)const;
    bool operator!=(const ImageStatus& other)const;

    virtual bool operator==(const Status& other) const override;
    virtual bool operator!=(const Status& other) const override;

private:
    ImageStatus(const ImageStatus& other);
    const ImageStatus& operator=(const ImageStatus&);
};

#endif //__IMAGE_STATUS_H
