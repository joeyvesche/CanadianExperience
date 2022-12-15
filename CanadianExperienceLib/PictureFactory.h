/**
 * @file PictureFactory.h
 * @author joeyv
 *
 *
 */

#ifndef CANADIANEXPERIENCE_PICTUREFACTORY_H
#define CANADIANEXPERIENCE_PICTUREFACTORY_H

class Picture;

/**
 * A factory class that builds our picture.
 */
class PictureFactory {
private:

public:
    std::shared_ptr<Picture> Create(std::wstring imagesDir);

};

#endif //CANADIANEXPERIENCE_PICTUREFACTORY_H
