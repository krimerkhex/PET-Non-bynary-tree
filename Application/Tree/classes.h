#include <iostream>

class File {
    public:
        File() : file_type_("File"), file_name_(""), extension_(""), attributs_(5), methods_(6) {;}
        File(std::string file_type, std::string extension, std::string file_name, int attributs, int methods) :
        file_type_(file_type), file_name_(file_name), extension_(extension), attributs_(5 + attributs), methods_(6 + methods) {;}
        ~File() = default;

        std::string getFileType() { return this->file_type_; }
        std::string getFileName() { return this->file_name_; }
        std::string getFileExtension() { return this->extension_; }
        int getAttributs() { return this->attributs_; }
        int getMethods() { return this->methods_; }

        virtual void print() {
            std::cout <<"File |\n\tType : " << file_type_<<"|\n\tName : "<< file_name_ <<"|\n\tExtension : "<<extension_<<
            "|\n\tAtribbuts : "<<attributs_<<"|\n\tMethods : "<<methods_<< std::endl;
        }

    protected:
        std::string file_type_;
        std::string extension_;
        std::string file_name_;
        int attributs_;
        int methods_;
};

class TextFile : public File {
    public:
        TextFile() : File("TextFile", ".txt", "", 3, 7), text_(""), encoding_(""), words_(text_.size()) {;}
        TextFile(std::string file_name) :
        File("TextFile", ".txt", file_name, 3, 7), text_(""), encoding_("Unicode"), words_(text_.size()) {;}
        TextFile(std::string file_name, std::string text) :
        File("TextFile", ".txt", file_name, 3, 7), text_(text), encoding_("Unicode"), words_(text_.size()) {;}
        ~TextFile() = default;

        void addText(std::string in_v) { text_ = text_ + in_v; }
        void clear() { text_ = ""; words_ = 0; }
        void setText(std::string text) { text_ = text; words_ = text_.size(); } 
        void setEncoding(std::string code) { encoding_ = code; }
        std::string getText() { return text_; }
        std::string getEncoding() { return encoding_; }
        int getWords() { return words_; }
        virtual void print() {
            std::cout <<"File |\n\tType : " <<file_type_<<"|\n\tName : "<< file_name_ <<"|\n\tExtension : "<<extension_<<
            "|\n\tAtribbuts : "<<attributs_<<"|\n\tMethods : "<<methods_ <<"|\n\tText : "<<text_<<"|\n\tEncoding : "<<encoding_
            <<"|\n\tWords : "<<words_<< std::endl;
        }

    private:
        std::string text_;
        std::string encoding_;
        int words_;
};

class DocumentFile: public File {
    public:
        DocumentFile() : File("DocumentFile", ".doc", "", 3, 7), text_(""), encoding_(""), words_(text_.size()) {;}
        DocumentFile(std::string file_name) :
        File("DocumentFile", "", file_name, 3, 7), text_(""), encoding_("Unicode"), words_(text_.size()) {;}
        DocumentFile(std::string file_name, std::string extension, std::string text) :
        File("DocumentFile", "." + extension, file_name, 3, 7), text_(text), encoding_("Unicode"), words_(text_.size()) {;}
        ~DocumentFile() = default;

        void addText(std::string in_v) { text_ = text_ + in_v; }
        void clear() { text_ = ""; words_ = 0; }
        void setText(std::string text) { text_ = text; words_ = text_.size(); } 
        void setEncoding(std::string code) { encoding_ = code; }
        std::string getText() { return text_; }
        std::string getEncoding() { return encoding_; }
        int getWords() { return words_; }
        virtual void print() {
            std::cout <<"File |\n\tType : " <<file_type_<<"|\n\tName : "<< file_name_ <<"|\n\tExtension : "<<extension_<<
            "|\n\tAtribbuts : "<<attributs_<<"|\n\tMethods : "<<methods_ <<"|\n\tText : "<<text_<<"|\n\tEncoding : "<<encoding_
            <<"|\n\tWords : "<<words_<< std::endl;
        }

    private:
        std::string text_;
        std::string encoding_;
        int words_;
};

class TableFile : public File {
    public:
        TableFile() : File("TableFile", ".xlsx", "", 3, 5), rows_(0), cols_(0), cells_(0) {;}
        TableFile(std::string file_name)
        : File("TableFile", "", file_name, 3, 5), rows_(0), cols_(0), cells_(rows_ * cols_) {;}
        TableFile(std::string file_name, std::string extension, int row, int col)
        : File("TableFile", "." + extension, file_name, 3, 5), rows_(row), cols_(col), cells_(rows_ * cols_) {;}
        ~TableFile() = default;

        void setRows(int row) { rows_ = row; cells_ = rows_ * cols_; }
        void setCols(int col) { cols_ = col; cells_ = rows_ * cols_; }

        int getRows() { return rows_; }
        int getCols() { return cols_; }
        int getCells() { return cells_; }

        virtual void print() {
            std::cout <<"File |\n\tType : " << file_type_<<"|\n\tName : "<< file_name_ <<"|\n\tExtension : "<<extension_<<
            "|\n\tAtribbuts : "<<attributs_<<"|\n\tMethods : "<<methods_<<"|\n\tRows : "<<rows_<<"|\n\tCols : "<<cols_<<"|\n\tCells : "<<cells_<< std::endl;
        }

    private:
        int rows_;
        int cols_;
        int cells_;
};

class ImagenFile : public File {
    public:
        ImagenFile() : File() {;}
        ImagenFile(std::string file_name)
        : File("ImagenFile", "", file_name, 3, 5), height_(0), weight_(0), pixels_(height_ * weight_) {;}
        ImagenFile(std::string file_name, std::string extension, int he, int we)
        : File("ImagenFile", "." + extension, file_name, 3, 5), height_(he), weight_(we), pixels_(height_ * weight_) {;}
        ~ImagenFile() = default;
    
        void setHeight(int he) { height_ = he; pixels_ = height_ * weight_; }
        void setWeight(int we) { weight_ = we; pixels_ = height_ * weight_; }

        int getHeight() { return height_; }
        int getWeight() { return weight_; }
        int getPixels() { return pixels_; }

        virtual void print() {
            std::cout <<"File |\n\tType : " << file_type_<<"|\n\tName : "<< file_name_ <<"|\n\tExtension : "<<extension_<<
            "|\n\tAtribbuts : "<<attributs_<<"|\n\tMethods : "<<methods_<<"|\n\tHeight : "<<height_<<"|\n\tWeight : "<<weight_<<"|\n\tPixels : "<<pixels_<< std::endl;
        }
        
    private:
        int height_;
        int weight_;
        int pixels_;
};

class VideoFile : public File {
    public:
        VideoFile() : File(), height_(0), weight_(0), time_(0), pixels_(0) {;}
        VideoFile(std::string file_name)
        : File("VideoFile", "", file_name, 4, 6), height_(0), weight_(0), time_(0), pixels_(height_ * weight_ * time_) {;}
        VideoFile(std::string file_name, std::string extension, int he, int we, int ti)
        : File("VideoFile", "." + extension, file_name, 4, 6), height_(he), weight_(we), time_(ti), pixels_(height_ * weight_ * time_) {;}
        ~VideoFile() = default;
    
        void setHeight(int he) { height_ = he; pixels_ = height_ * weight_ * time_; }
        void setWeight(int we) { weight_ = we; pixels_ = height_ * weight_ * time_; }
        void setTime(int ti) { time_ = ti; pixels_ = height_ * weight_ * time_; }

        int getHeight() { return height_; }
        int getWeight() { return weight_; }
        int getTime() { return time_; }
        int getPixels() { return pixels_; }

        virtual void print() {
            std::cout <<"File |\n\tType : " << file_type_<<"|\n\tName : "<< file_name_ <<"|\n\tExtension : "<<extension_<<
            "|\n\tAtribbuts : "<<attributs_<<"|\n\tMethods : "<<methods_<<"|\n\tHeight : "<<height_<<"|\n\tWeight : "<<weight_<<"|\n\tTime : "<<time_<<"|\n\tPixels : "<<pixels_<< std::endl;
        }
        
    private:
        int height_;
        int time_;
        int weight_;
        int pixels_;
};
