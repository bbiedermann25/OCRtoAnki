#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main() {
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract to use Korean (kor) and English (eng) and the LSTM OCR engine.
    if (api->Init(NULL, "kor+eng", tesseract::OEM_LSTM_ONLY)) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        return 1;
    }

    // Open input image with leptonica library
    Pix *image = pixRead("images/IMG_7516.jpeg");
    api->SetImage(image);
    
    // Get OCR result
    char *outText = api->GetUTF8Text();
    printf("OCR Output:\n%s", outText);

    // Clean up
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}