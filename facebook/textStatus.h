#ifndef __TEXT_STATUS_H
#define __TEXT_STATUS_H

#include "status.h"

#include <iostream>
#include <string>

class TextStatus:public Status
{
    std::string text;
public:
    TextStatus(const std::string& text) noexcept(false)
        : text(text), Status(eColor::BLACK_AND_WHITE, eSoftware::SIMPLE)
    {
        if (text == "") throw EmptyTextException();
    }

    virtual void toOs(std::ostream& os) const override;

    bool operator==(const TextStatus& other)const;
    bool operator!=(const TextStatus& other)const;

    virtual bool operator==(const Status& other) const override;
    virtual bool operator!=(const Status& other) const override;


private:
    TextStatus(const TextStatus& other);
    const TextStatus& operator=(const TextStatus&);
};

#endif //__TEXT_STATUS_H