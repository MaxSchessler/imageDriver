
/**
 * A structure that represents a single pixel value using
 * the RGB (red-blue-green) color model.  Each integer
 * value is in the range [0, 255].
 */
typedef struct {
  int red;
  int green;
  int blue;
} Pixel;

/**
 * Loads an image file specified by the given file path/name.
 * The height and width are indicated in the two pass-by-reference variables.
 * The image is returned as a two-dimensional array of Pixel values
 * of dimension (height x width) where the pixel at [0][0] corresponds to
 * the top-left most pixel value.
 */
Pixel **loadImage(const char *filePath, int *height, int *width);

/**
 * Saves the given image (which is assumed to have the same format as in
 * loadImage() and is of the given height x width) to the file specified
 * by the given path/name.
 */
void saveImage(const char *filePath, Pixel **image, int height, int width);

/**
 * Copies an image.
 * @param image A 2D array of Pixel objects representing the image to be copied.
 * @param height The height of the image.
 * @param width The width of the image.
 * @return A new 2D array of Pixel objects representing the copied image.
 */
Pixel ** copyImage(Pixel **image, int height, int width);


/**
 * @brief Copies and rotates an image 90 degrees clockwise.
 *
 * This function takes an input image represented as a 2D array of Pixels and 
 * returns a new image that is a rotated copy of the original image. The 
 * rotation is performed 90 degrees clockwise.
 *
 * @param image The original image represented as a 2D array of Pixels.
 * @param height The height of the original image.
 * @param width The width of the original image.
 * @return A new 2D array of Pixels representing the rotated image.
 */
Pixel **transpose(Pixel **image, int height, int widt, int *tHeight, int *tWidth);

/**
 * This function will reverse every row in the 2D array of Pixels in order to complete the rotation of the image.
 * 
 * @param image The original image represented as a 2D array of Pixels.
 * @param height The height of the original image.
 * @param width The width of the original image.=
 */
void reverseRows(Pixel **image, int height, int width);

/**
 * FLips the given image horizontally.
 * @param image A 2D array of Pixel objects representing the image to be flipped.
 * @param height The height of the image.
 * @param width The width of the image.
 * @return A new 2D array of Pixel objects representing the flipped image.
 */
void flipHorizontal(Pixel **image, int height, int width);

/**
 * Flips the given image vertically.
 * @param image A 2D array of Pixel objects representing the image to be flipped.
 * @param height The height of the image.
 * @param width The width of the image.
 * @return A new 2D array of Pixel objects representing the flipped image.
 */
void flipVertical(Pixel **image, int height, int width);

/**
 * Rotates the given image 90 degrees clockwise.
 *
 * @param image A 2D array of Pixel objects representing the image to be rotated.
 * @param height The height of the image.
 * @param width The width of the image.
 * @return A new 2D array of Pixel objects representing the rotated image.
 */
Pixel ** rotateClockwise(Pixel **image, int height, int width);

