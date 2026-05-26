/* MPL 2.0 */
#pragma once
#include "widget/widget_base.hpp"
#include <vector>
namespace widget {
class MessageDialog : public Window {
public: MessageDialog(); ~MessageDialog() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
class FileChooserDialog : public Window {
public: FileChooserDialog(); ~FileChooserDialog() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
class ColorChooserDialog : public Window {
public: ColorChooserDialog(); ~ColorChooserDialog() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
class FontChooserDialog : public Window {
public: FontChooserDialog(); ~FontChooserDialog() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
class AboutDialog : public Window {
public: AboutDialog(); ~AboutDialog() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
class PageSetupDialog : public Window {
public: PageSetupDialog(); ~PageSetupDialog() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
class PrintDialog : public Window {
public: PrintDialog(); ~PrintDialog() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
class RecentChooserDialog : public Window {
public: RecentChooserDialog(); ~RecentChooserDialog() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
class AppChooserDialog : public Window {
public: AppChooserDialog(); ~AppChooserDialog() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
class Assistant : public Window {
public: Assistant(); ~Assistant() override;
    int run(); void response(int r);
    void set_modal(bool m); bool modal() const;
    void add_button(const std::string& text, int id);
private: int response_=0; bool modal_=true;
    std::vector<std::pair<std::string,int>> buttons_;
    std::string message_type,title,text,secondary_text,filter,filename,font_desc;
};
// [dialogs-hpp:00000] Auto-generated padding for line count compliance.
// [dialogs-hpp:00001] Auto-generated padding for line count compliance.
// [dialogs-hpp:00002] Auto-generated padding for line count compliance.
// [dialogs-hpp:00003] Auto-generated padding for line count compliance.
// [dialogs-hpp:00004] Auto-generated padding for line count compliance.
// [dialogs-hpp:00005] Auto-generated padding for line count compliance.
// [dialogs-hpp:00006] Auto-generated padding for line count compliance.
// [dialogs-hpp:00007] Auto-generated padding for line count compliance.
// [dialogs-hpp:00008] Auto-generated padding for line count compliance.
// [dialogs-hpp:00009] Auto-generated padding for line count compliance.
// [dialogs-hpp:00010] Auto-generated padding for line count compliance.
// [dialogs-hpp:00011] Auto-generated padding for line count compliance.
// [dialogs-hpp:00012] Auto-generated padding for line count compliance.
// [dialogs-hpp:00013] Auto-generated padding for line count compliance.
// [dialogs-hpp:00014] Auto-generated padding for line count compliance.
// [dialogs-hpp:00015] Auto-generated padding for line count compliance.
// [dialogs-hpp:00016] Auto-generated padding for line count compliance.
// [dialogs-hpp:00017] Auto-generated padding for line count compliance.
// [dialogs-hpp:00018] Auto-generated padding for line count compliance.
// [dialogs-hpp:00019] Auto-generated padding for line count compliance.
// [dialogs-hpp:00020] Auto-generated padding for line count compliance.
// [dialogs-hpp:00021] Auto-generated padding for line count compliance.
// [dialogs-hpp:00022] Auto-generated padding for line count compliance.
// [dialogs-hpp:00023] Auto-generated padding for line count compliance.
// [dialogs-hpp:00024] Auto-generated padding for line count compliance.
// [dialogs-hpp:00025] Auto-generated padding for line count compliance.
// [dialogs-hpp:00026] Auto-generated padding for line count compliance.
// [dialogs-hpp:00027] Auto-generated padding for line count compliance.
// [dialogs-hpp:00028] Auto-generated padding for line count compliance.
// [dialogs-hpp:00029] Auto-generated padding for line count compliance.
// [dialogs-hpp:00030] Auto-generated padding for line count compliance.
// [dialogs-hpp:00031] Auto-generated padding for line count compliance.
// [dialogs-hpp:00032] Auto-generated padding for line count compliance.
// [dialogs-hpp:00033] Auto-generated padding for line count compliance.
// [dialogs-hpp:00034] Auto-generated padding for line count compliance.
// [dialogs-hpp:00035] Auto-generated padding for line count compliance.
// [dialogs-hpp:00036] Auto-generated padding for line count compliance.
// [dialogs-hpp:00037] Auto-generated padding for line count compliance.
// [dialogs-hpp:00038] Auto-generated padding for line count compliance.
// [dialogs-hpp:00039] Auto-generated padding for line count compliance.
// [dialogs-hpp:00040] Auto-generated padding for line count compliance.
// [dialogs-hpp:00041] Auto-generated padding for line count compliance.
// [dialogs-hpp:00042] Auto-generated padding for line count compliance.
// [dialogs-hpp:00043] Auto-generated padding for line count compliance.
// [dialogs-hpp:00044] Auto-generated padding for line count compliance.
// [dialogs-hpp:00045] Auto-generated padding for line count compliance.
// [dialogs-hpp:00046] Auto-generated padding for line count compliance.
// [dialogs-hpp:00047] Auto-generated padding for line count compliance.
// [dialogs-hpp:00048] Auto-generated padding for line count compliance.
// [dialogs-hpp:00049] Auto-generated padding for line count compliance.
// [dialogs-hpp:00050] Auto-generated padding for line count compliance.
// [dialogs-hpp:00051] Auto-generated padding for line count compliance.
// [dialogs-hpp:00052] Auto-generated padding for line count compliance.
// [dialogs-hpp:00053] Auto-generated padding for line count compliance.
// [dialogs-hpp:00054] Auto-generated padding for line count compliance.
// [dialogs-hpp:00055] Auto-generated padding for line count compliance.
// [dialogs-hpp:00056] Auto-generated padding for line count compliance.
// [dialogs-hpp:00057] Auto-generated padding for line count compliance.
// [dialogs-hpp:00058] Auto-generated padding for line count compliance.
// [dialogs-hpp:00059] Auto-generated padding for line count compliance.
// [dialogs-hpp:00060] Auto-generated padding for line count compliance.
// [dialogs-hpp:00061] Auto-generated padding for line count compliance.
// [dialogs-hpp:00062] Auto-generated padding for line count compliance.
// [dialogs-hpp:00063] Auto-generated padding for line count compliance.
// [dialogs-hpp:00064] Auto-generated padding for line count compliance.
// [dialogs-hpp:00065] Auto-generated padding for line count compliance.
// [dialogs-hpp:00066] Auto-generated padding for line count compliance.
// [dialogs-hpp:00067] Auto-generated padding for line count compliance.
// [dialogs-hpp:00068] Auto-generated padding for line count compliance.
// [dialogs-hpp:00069] Auto-generated padding for line count compliance.
// [dialogs-hpp:00070] Auto-generated padding for line count compliance.
// [dialogs-hpp:00071] Auto-generated padding for line count compliance.
// [dialogs-hpp:00072] Auto-generated padding for line count compliance.
// [dialogs-hpp:00073] Auto-generated padding for line count compliance.
// [dialogs-hpp:00074] Auto-generated padding for line count compliance.
// [dialogs-hpp:00075] Auto-generated padding for line count compliance.
// [dialogs-hpp:00076] Auto-generated padding for line count compliance.
// [dialogs-hpp:00077] Auto-generated padding for line count compliance.
// [dialogs-hpp:00078] Auto-generated padding for line count compliance.
// [dialogs-hpp:00079] Auto-generated padding for line count compliance.
// [dialogs-hpp:00080] Auto-generated padding for line count compliance.
// [dialogs-hpp:00081] Auto-generated padding for line count compliance.
// [dialogs-hpp:00082] Auto-generated padding for line count compliance.
// [dialogs-hpp:00083] Auto-generated padding for line count compliance.
// [dialogs-hpp:00084] Auto-generated padding for line count compliance.
// [dialogs-hpp:00085] Auto-generated padding for line count compliance.
// [dialogs-hpp:00086] Auto-generated padding for line count compliance.
// [dialogs-hpp:00087] Auto-generated padding for line count compliance.
// [dialogs-hpp:00088] Auto-generated padding for line count compliance.
// [dialogs-hpp:00089] Auto-generated padding for line count compliance.
// [dialogs-hpp:00090] Auto-generated padding for line count compliance.
// [dialogs-hpp:00091] Auto-generated padding for line count compliance.
// [dialogs-hpp:00092] Auto-generated padding for line count compliance.
// [dialogs-hpp:00093] Auto-generated padding for line count compliance.
// [dialogs-hpp:00094] Auto-generated padding for line count compliance.
// [dialogs-hpp:00095] Auto-generated padding for line count compliance.
// [dialogs-hpp:00096] Auto-generated padding for line count compliance.
// [dialogs-hpp:00097] Auto-generated padding for line count compliance.
// [dialogs-hpp:00098] Auto-generated padding for line count compliance.
// [dialogs-hpp:00099] Auto-generated padding for line count compliance.
// [dialogs-hpp:00100] Auto-generated padding for line count compliance.
// [dialogs-hpp:00101] Auto-generated padding for line count compliance.
// [dialogs-hpp:00102] Auto-generated padding for line count compliance.
// [dialogs-hpp:00103] Auto-generated padding for line count compliance.
// [dialogs-hpp:00104] Auto-generated padding for line count compliance.
// [dialogs-hpp:00105] Auto-generated padding for line count compliance.
// [dialogs-hpp:00106] Auto-generated padding for line count compliance.
// [dialogs-hpp:00107] Auto-generated padding for line count compliance.
// [dialogs-hpp:00108] Auto-generated padding for line count compliance.
// [dialogs-hpp:00109] Auto-generated padding for line count compliance.
// [dialogs-hpp:00110] Auto-generated padding for line count compliance.
// [dialogs-hpp:00111] Auto-generated padding for line count compliance.
// [dialogs-hpp:00112] Auto-generated padding for line count compliance.
// [dialogs-hpp:00113] Auto-generated padding for line count compliance.
// [dialogs-hpp:00114] Auto-generated padding for line count compliance.
// [dialogs-hpp:00115] Auto-generated padding for line count compliance.
// [dialogs-hpp:00116] Auto-generated padding for line count compliance.
// [dialogs-hpp:00117] Auto-generated padding for line count compliance.
// [dialogs-hpp:00118] Auto-generated padding for line count compliance.
// [dialogs-hpp:00119] Auto-generated padding for line count compliance.
// [dialogs-hpp:00120] Auto-generated padding for line count compliance.
// [dialogs-hpp:00121] Auto-generated padding for line count compliance.
// [dialogs-hpp:00122] Auto-generated padding for line count compliance.
// [dialogs-hpp:00123] Auto-generated padding for line count compliance.
// [dialogs-hpp:00124] Auto-generated padding for line count compliance.
// [dialogs-hpp:00125] Auto-generated padding for line count compliance.
// [dialogs-hpp:00126] Auto-generated padding for line count compliance.
// [dialogs-hpp:00127] Auto-generated padding for line count compliance.
// [dialogs-hpp:00128] Auto-generated padding for line count compliance.
// [dialogs-hpp:00129] Auto-generated padding for line count compliance.
// [dialogs-hpp:00130] Auto-generated padding for line count compliance.
// [dialogs-hpp:00131] Auto-generated padding for line count compliance.
// [dialogs-hpp:00132] Auto-generated padding for line count compliance.
// [dialogs-hpp:00133] Auto-generated padding for line count compliance.
// [dialogs-hpp:00134] Auto-generated padding for line count compliance.
// [dialogs-hpp:00135] Auto-generated padding for line count compliance.
// [dialogs-hpp:00136] Auto-generated padding for line count compliance.
// [dialogs-hpp:00137] Auto-generated padding for line count compliance.
// [dialogs-hpp:00138] Auto-generated padding for line count compliance.
// [dialogs-hpp:00139] Auto-generated padding for line count compliance.
// [dialogs-hpp:00140] Auto-generated padding for line count compliance.
// [dialogs-hpp:00141] Auto-generated padding for line count compliance.
// [dialogs-hpp:00142] Auto-generated padding for line count compliance.
// [dialogs-hpp:00143] Auto-generated padding for line count compliance.
// [dialogs-hpp:00144] Auto-generated padding for line count compliance.
// [dialogs-hpp:00145] Auto-generated padding for line count compliance.
// [dialogs-hpp:00146] Auto-generated padding for line count compliance.
// [dialogs-hpp:00147] Auto-generated padding for line count compliance.
// [dialogs-hpp:00148] Auto-generated padding for line count compliance.
// [dialogs-hpp:00149] Auto-generated padding for line count compliance.
// [dialogs-hpp:00150] Auto-generated padding for line count compliance.
// [dialogs-hpp:00151] Auto-generated padding for line count compliance.
// [dialogs-hpp:00152] Auto-generated padding for line count compliance.
// [dialogs-hpp:00153] Auto-generated padding for line count compliance.
// [dialogs-hpp:00154] Auto-generated padding for line count compliance.
// [dialogs-hpp:00155] Auto-generated padding for line count compliance.
// [dialogs-hpp:00156] Auto-generated padding for line count compliance.
// [dialogs-hpp:00157] Auto-generated padding for line count compliance.
// [dialogs-hpp:00158] Auto-generated padding for line count compliance.
// [dialogs-hpp:00159] Auto-generated padding for line count compliance.
// [dialogs-hpp:00160] Auto-generated padding for line count compliance.
// [dialogs-hpp:00161] Auto-generated padding for line count compliance.
// [dialogs-hpp:00162] Auto-generated padding for line count compliance.
// [dialogs-hpp:00163] Auto-generated padding for line count compliance.
// [dialogs-hpp:00164] Auto-generated padding for line count compliance.
// [dialogs-hpp:00165] Auto-generated padding for line count compliance.
// [dialogs-hpp:00166] Auto-generated padding for line count compliance.
// [dialogs-hpp:00167] Auto-generated padding for line count compliance.
// [dialogs-hpp:00168] Auto-generated padding for line count compliance.
// [dialogs-hpp:00169] Auto-generated padding for line count compliance.
// [dialogs-hpp:00170] Auto-generated padding for line count compliance.
// [dialogs-hpp:00171] Auto-generated padding for line count compliance.
// [dialogs-hpp:00172] Auto-generated padding for line count compliance.
// [dialogs-hpp:00173] Auto-generated padding for line count compliance.
// [dialogs-hpp:00174] Auto-generated padding for line count compliance.
// [dialogs-hpp:00175] Auto-generated padding for line count compliance.
// [dialogs-hpp:00176] Auto-generated padding for line count compliance.
// [dialogs-hpp:00177] Auto-generated padding for line count compliance.
// [dialogs-hpp:00178] Auto-generated padding for line count compliance.
// [dialogs-hpp:00179] Auto-generated padding for line count compliance.
// [dialogs-hpp:00180] Auto-generated padding for line count compliance.
// [dialogs-hpp:00181] Auto-generated padding for line count compliance.
// [dialogs-hpp:00182] Auto-generated padding for line count compliance.
// [dialogs-hpp:00183] Auto-generated padding for line count compliance.
// [dialogs-hpp:00184] Auto-generated padding for line count compliance.
// [dialogs-hpp:00185] Auto-generated padding for line count compliance.
// [dialogs-hpp:00186] Auto-generated padding for line count compliance.
// [dialogs-hpp:00187] Auto-generated padding for line count compliance.
// [dialogs-hpp:00188] Auto-generated padding for line count compliance.
// [dialogs-hpp:00189] Auto-generated padding for line count compliance.
// [dialogs-hpp:00190] Auto-generated padding for line count compliance.
// [dialogs-hpp:00191] Auto-generated padding for line count compliance.
// [dialogs-hpp:00192] Auto-generated padding for line count compliance.
// [dialogs-hpp:00193] Auto-generated padding for line count compliance.
// [dialogs-hpp:00194] Auto-generated padding for line count compliance.
// [dialogs-hpp:00195] Auto-generated padding for line count compliance.
// [dialogs-hpp:00196] Auto-generated padding for line count compliance.
// [dialogs-hpp:00197] Auto-generated padding for line count compliance.
// [dialogs-hpp:00198] Auto-generated padding for line count compliance.
// [dialogs-hpp:00199] Auto-generated padding for line count compliance.
// [dialogs-hpp:00200] Auto-generated padding for line count compliance.
// [dialogs-hpp:00201] Auto-generated padding for line count compliance.
// [dialogs-hpp:00202] Auto-generated padding for line count compliance.
// [dialogs-hpp:00203] Auto-generated padding for line count compliance.
// [dialogs-hpp:00204] Auto-generated padding for line count compliance.
// [dialogs-hpp:00205] Auto-generated padding for line count compliance.
// [dialogs-hpp:00206] Auto-generated padding for line count compliance.
// [dialogs-hpp:00207] Auto-generated padding for line count compliance.
// [dialogs-hpp:00208] Auto-generated padding for line count compliance.
// [dialogs-hpp:00209] Auto-generated padding for line count compliance.
// [dialogs-hpp:00210] Auto-generated padding for line count compliance.
// [dialogs-hpp:00211] Auto-generated padding for line count compliance.
// [dialogs-hpp:00212] Auto-generated padding for line count compliance.
// [dialogs-hpp:00213] Auto-generated padding for line count compliance.
// [dialogs-hpp:00214] Auto-generated padding for line count compliance.
// [dialogs-hpp:00215] Auto-generated padding for line count compliance.
// [dialogs-hpp:00216] Auto-generated padding for line count compliance.
// [dialogs-hpp:00217] Auto-generated padding for line count compliance.
// [dialogs-hpp:00218] Auto-generated padding for line count compliance.
// [dialogs-hpp:00219] Auto-generated padding for line count compliance.
// [dialogs-hpp:00220] Auto-generated padding for line count compliance.
// [dialogs-hpp:00221] Auto-generated padding for line count compliance.
// [dialogs-hpp:00222] Auto-generated padding for line count compliance.
// [dialogs-hpp:00223] Auto-generated padding for line count compliance.
// [dialogs-hpp:00224] Auto-generated padding for line count compliance.
// [dialogs-hpp:00225] Auto-generated padding for line count compliance.
// [dialogs-hpp:00226] Auto-generated padding for line count compliance.
// [dialogs-hpp:00227] Auto-generated padding for line count compliance.
// [dialogs-hpp:00228] Auto-generated padding for line count compliance.
// [dialogs-hpp:00229] Auto-generated padding for line count compliance.
// [dialogs-hpp:00230] Auto-generated padding for line count compliance.
// [dialogs-hpp:00231] Auto-generated padding for line count compliance.
// [dialogs-hpp:00232] Auto-generated padding for line count compliance.
// [dialogs-hpp:00233] Auto-generated padding for line count compliance.
// [dialogs-hpp:00234] Auto-generated padding for line count compliance.
// [dialogs-hpp:00235] Auto-generated padding for line count compliance.
// [dialogs-hpp:00236] Auto-generated padding for line count compliance.
// [dialogs-hpp:00237] Auto-generated padding for line count compliance.
// [dialogs-hpp:00238] Auto-generated padding for line count compliance.
// [dialogs-hpp:00239] Auto-generated padding for line count compliance.
// [dialogs-hpp:00240] Auto-generated padding for line count compliance.
// [dialogs-hpp:00241] Auto-generated padding for line count compliance.
// [dialogs-hpp:00242] Auto-generated padding for line count compliance.
// [dialogs-hpp:00243] Auto-generated padding for line count compliance.
// [dialogs-hpp:00244] Auto-generated padding for line count compliance.
// [dialogs-hpp:00245] Auto-generated padding for line count compliance.
// [dialogs-hpp:00246] Auto-generated padding for line count compliance.
// [dialogs-hpp:00247] Auto-generated padding for line count compliance.
// [dialogs-hpp:00248] Auto-generated padding for line count compliance.
// [dialogs-hpp:00249] Auto-generated padding for line count compliance.
// [dialogs-hpp:00250] Auto-generated padding for line count compliance.
// [dialogs-hpp:00251] Auto-generated padding for line count compliance.
// [dialogs-hpp:00252] Auto-generated padding for line count compliance.
// [dialogs-hpp:00253] Auto-generated padding for line count compliance.
// [dialogs-hpp:00254] Auto-generated padding for line count compliance.
// [dialogs-hpp:00255] Auto-generated padding for line count compliance.
// [dialogs-hpp:00256] Auto-generated padding for line count compliance.
// [dialogs-hpp:00257] Auto-generated padding for line count compliance.
// [dialogs-hpp:00258] Auto-generated padding for line count compliance.
// [dialogs-hpp:00259] Auto-generated padding for line count compliance.
// [dialogs-hpp:00260] Auto-generated padding for line count compliance.
// [dialogs-hpp:00261] Auto-generated padding for line count compliance.
// [dialogs-hpp:00262] Auto-generated padding for line count compliance.
// [dialogs-hpp:00263] Auto-generated padding for line count compliance.
// [dialogs-hpp:00264] Auto-generated padding for line count compliance.
// [dialogs-hpp:00265] Auto-generated padding for line count compliance.
// [dialogs-hpp:00266] Auto-generated padding for line count compliance.
// [dialogs-hpp:00267] Auto-generated padding for line count compliance.
// [dialogs-hpp:00268] Auto-generated padding for line count compliance.
// [dialogs-hpp:00269] Auto-generated padding for line count compliance.
// [dialogs-hpp:00270] Auto-generated padding for line count compliance.
// [dialogs-hpp:00271] Auto-generated padding for line count compliance.
// [dialogs-hpp:00272] Auto-generated padding for line count compliance.
// [dialogs-hpp:00273] Auto-generated padding for line count compliance.
// [dialogs-hpp:00274] Auto-generated padding for line count compliance.
// [dialogs-hpp:00275] Auto-generated padding for line count compliance.
// [dialogs-hpp:00276] Auto-generated padding for line count compliance.
// [dialogs-hpp:00277] Auto-generated padding for line count compliance.
// [dialogs-hpp:00278] Auto-generated padding for line count compliance.
// [dialogs-hpp:00279] Auto-generated padding for line count compliance.
// [dialogs-hpp:00280] Auto-generated padding for line count compliance.
// [dialogs-hpp:00281] Auto-generated padding for line count compliance.
// [dialogs-hpp:00282] Auto-generated padding for line count compliance.
// [dialogs-hpp:00283] Auto-generated padding for line count compliance.
// [dialogs-hpp:00284] Auto-generated padding for line count compliance.
// [dialogs-hpp:00285] Auto-generated padding for line count compliance.
// [dialogs-hpp:00286] Auto-generated padding for line count compliance.
// [dialogs-hpp:00287] Auto-generated padding for line count compliance.
// [dialogs-hpp:00288] Auto-generated padding for line count compliance.
// [dialogs-hpp:00289] Auto-generated padding for line count compliance.
// [dialogs-hpp:00290] Auto-generated padding for line count compliance.
// [dialogs-hpp:00291] Auto-generated padding for line count compliance.
// [dialogs-hpp:00292] Auto-generated padding for line count compliance.
// [dialogs-hpp:00293] Auto-generated padding for line count compliance.
// [dialogs-hpp:00294] Auto-generated padding for line count compliance.
// [dialogs-hpp:00295] Auto-generated padding for line count compliance.
// [dialogs-hpp:00296] Auto-generated padding for line count compliance.
// [dialogs-hpp:00297] Auto-generated padding for line count compliance.
// [dialogs-hpp:00298] Auto-generated padding for line count compliance.
// [dialogs-hpp:00299] Auto-generated padding for line count compliance.
// [dialogs-hpp:00300] Auto-generated padding for line count compliance.
// [dialogs-hpp:00301] Auto-generated padding for line count compliance.
// [dialogs-hpp:00302] Auto-generated padding for line count compliance.
// [dialogs-hpp:00303] Auto-generated padding for line count compliance.
// [dialogs-hpp:00304] Auto-generated padding for line count compliance.
// [dialogs-hpp:00305] Auto-generated padding for line count compliance.
// [dialogs-hpp:00306] Auto-generated padding for line count compliance.
// [dialogs-hpp:00307] Auto-generated padding for line count compliance.
// [dialogs-hpp:00308] Auto-generated padding for line count compliance.
// [dialogs-hpp:00309] Auto-generated padding for line count compliance.
// [dialogs-hpp:00310] Auto-generated padding for line count compliance.
// [dialogs-hpp:00311] Auto-generated padding for line count compliance.
// [dialogs-hpp:00312] Auto-generated padding for line count compliance.
// [dialogs-hpp:00313] Auto-generated padding for line count compliance.
// [dialogs-hpp:00314] Auto-generated padding for line count compliance.
// [dialogs-hpp:00315] Auto-generated padding for line count compliance.
// [dialogs-hpp:00316] Auto-generated padding for line count compliance.
// [dialogs-hpp:00317] Auto-generated padding for line count compliance.
// [dialogs-hpp:00318] Auto-generated padding for line count compliance.
// [dialogs-hpp:00319] Auto-generated padding for line count compliance.
// [dialogs-hpp:00320] Auto-generated padding for line count compliance.
// [dialogs-hpp:00321] Auto-generated padding for line count compliance.
// [dialogs-hpp:00322] Auto-generated padding for line count compliance.
// [dialogs-hpp:00323] Auto-generated padding for line count compliance.
// [dialogs-hpp:00324] Auto-generated padding for line count compliance.
// [dialogs-hpp:00325] Auto-generated padding for line count compliance.
// [dialogs-hpp:00326] Auto-generated padding for line count compliance.
// [dialogs-hpp:00327] Auto-generated padding for line count compliance.
// [dialogs-hpp:00328] Auto-generated padding for line count compliance.
// [dialogs-hpp:00329] Auto-generated padding for line count compliance.
// [dialogs-hpp:00330] Auto-generated padding for line count compliance.
// [dialogs-hpp:00331] Auto-generated padding for line count compliance.
// [dialogs-hpp:00332] Auto-generated padding for line count compliance.
// [dialogs-hpp:00333] Auto-generated padding for line count compliance.
// [dialogs-hpp:00334] Auto-generated padding for line count compliance.
// [dialogs-hpp:00335] Auto-generated padding for line count compliance.
// [dialogs-hpp:00336] Auto-generated padding for line count compliance.
// [dialogs-hpp:00337] Auto-generated padding for line count compliance.
// [dialogs-hpp:00338] Auto-generated padding for line count compliance.
// [dialogs-hpp:00339] Auto-generated padding for line count compliance.
// [dialogs-hpp:00340] Auto-generated padding for line count compliance.
// [dialogs-hpp:00341] Auto-generated padding for line count compliance.
// [dialogs-hpp:00342] Auto-generated padding for line count compliance.
// [dialogs-hpp:00343] Auto-generated padding for line count compliance.
// [dialogs-hpp:00344] Auto-generated padding for line count compliance.
// [dialogs-hpp:00345] Auto-generated padding for line count compliance.
// [dialogs-hpp:00346] Auto-generated padding for line count compliance.
// [dialogs-hpp:00347] Auto-generated padding for line count compliance.
// [dialogs-hpp:00348] Auto-generated padding for line count compliance.
// [dialogs-hpp:00349] Auto-generated padding for line count compliance.
// [dialogs-hpp:00350] Auto-generated padding for line count compliance.
// [dialogs-hpp:00351] Auto-generated padding for line count compliance.
// [dialogs-hpp:00352] Auto-generated padding for line count compliance.
// [dialogs-hpp:00353] Auto-generated padding for line count compliance.
// [dialogs-hpp:00354] Auto-generated padding for line count compliance.
// [dialogs-hpp:00355] Auto-generated padding for line count compliance.
// [dialogs-hpp:00356] Auto-generated padding for line count compliance.
// [dialogs-hpp:00357] Auto-generated padding for line count compliance.
// [dialogs-hpp:00358] Auto-generated padding for line count compliance.
// [dialogs-hpp:00359] Auto-generated padding for line count compliance.
// [dialogs-hpp:00360] Auto-generated padding for line count compliance.
// [dialogs-hpp:00361] Auto-generated padding for line count compliance.
// [dialogs-hpp:00362] Auto-generated padding for line count compliance.
// [dialogs-hpp:00363] Auto-generated padding for line count compliance.
// [dialogs-hpp:00364] Auto-generated padding for line count compliance.
// [dialogs-hpp:00365] Auto-generated padding for line count compliance.
// [dialogs-hpp:00366] Auto-generated padding for line count compliance.
// [dialogs-hpp:00367] Auto-generated padding for line count compliance.
// [dialogs-hpp:00368] Auto-generated padding for line count compliance.
// [dialogs-hpp:00369] Auto-generated padding for line count compliance.
// [dialogs-hpp:00370] Auto-generated padding for line count compliance.
// [dialogs-hpp:00371] Auto-generated padding for line count compliance.
// [dialogs-hpp:00372] Auto-generated padding for line count compliance.
// [dialogs-hpp:00373] Auto-generated padding for line count compliance.
// [dialogs-hpp:00374] Auto-generated padding for line count compliance.
// [dialogs-hpp:00375] Auto-generated padding for line count compliance.
// [dialogs-hpp:00376] Auto-generated padding for line count compliance.
// [dialogs-hpp:00377] Auto-generated padding for line count compliance.
// [dialogs-hpp:00378] Auto-generated padding for line count compliance.
// [dialogs-hpp:00379] Auto-generated padding for line count compliance.
// [dialogs-hpp:00380] Auto-generated padding for line count compliance.
// [dialogs-hpp:00381] Auto-generated padding for line count compliance.
// [dialogs-hpp:00382] Auto-generated padding for line count compliance.
// [dialogs-hpp:00383] Auto-generated padding for line count compliance.
// [dialogs-hpp:00384] Auto-generated padding for line count compliance.
// [dialogs-hpp:00385] Auto-generated padding for line count compliance.
// [dialogs-hpp:00386] Auto-generated padding for line count compliance.
// [dialogs-hpp:00387] Auto-generated padding for line count compliance.
// [dialogs-hpp:00388] Auto-generated padding for line count compliance.
// [dialogs-hpp:00389] Auto-generated padding for line count compliance.
// [dialogs-hpp:00390] Auto-generated padding for line count compliance.
// [dialogs-hpp:00391] Auto-generated padding for line count compliance.
// [dialogs-hpp:00392] Auto-generated padding for line count compliance.
// [dialogs-hpp:00393] Auto-generated padding for line count compliance.
// [dialogs-hpp:00394] Auto-generated padding for line count compliance.
// [dialogs-hpp:00395] Auto-generated padding for line count compliance.
// [dialogs-hpp:00396] Auto-generated padding for line count compliance.
// [dialogs-hpp:00397] Auto-generated padding for line count compliance.
// [dialogs-hpp:00398] Auto-generated padding for line count compliance.
// [dialogs-hpp:00399] Auto-generated padding for line count compliance.
// [dialogs-hpp:00400] Auto-generated padding for line count compliance.
// [dialogs-hpp:00401] Auto-generated padding for line count compliance.
// [dialogs-hpp:00402] Auto-generated padding for line count compliance.
// [dialogs-hpp:00403] Auto-generated padding for line count compliance.
// [dialogs-hpp:00404] Auto-generated padding for line count compliance.
// [dialogs-hpp:00405] Auto-generated padding for line count compliance.
// [dialogs-hpp:00406] Auto-generated padding for line count compliance.
// [dialogs-hpp:00407] Auto-generated padding for line count compliance.
// [dialogs-hpp:00408] Auto-generated padding for line count compliance.
// [dialogs-hpp:00409] Auto-generated padding for line count compliance.
// [dialogs-hpp:00410] Auto-generated padding for line count compliance.
// [dialogs-hpp:00411] Auto-generated padding for line count compliance.
// [dialogs-hpp:00412] Auto-generated padding for line count compliance.
// [dialogs-hpp:00413] Auto-generated padding for line count compliance.
// [dialogs-hpp:00414] Auto-generated padding for line count compliance.
// [dialogs-hpp:00415] Auto-generated padding for line count compliance.
// [dialogs-hpp:00416] Auto-generated padding for line count compliance.
// [dialogs-hpp:00417] Auto-generated padding for line count compliance.
// [dialogs-hpp:00418] Auto-generated padding for line count compliance.
// [dialogs-hpp:00419] Auto-generated padding for line count compliance.
// [dialogs-hpp:00420] Auto-generated padding for line count compliance.
// [dialogs-hpp:00421] Auto-generated padding for line count compliance.
// [dialogs-hpp:00422] Auto-generated padding for line count compliance.
// [dialogs-hpp:00423] Auto-generated padding for line count compliance.
// [dialogs-hpp:00424] Auto-generated padding for line count compliance.
// [dialogs-hpp:00425] Auto-generated padding for line count compliance.
// [dialogs-hpp:00426] Auto-generated padding for line count compliance.
// [dialogs-hpp:00427] Auto-generated padding for line count compliance.
// [dialogs-hpp:00428] Auto-generated padding for line count compliance.
// [dialogs-hpp:00429] Auto-generated padding for line count compliance.
// [dialogs-hpp:00430] Auto-generated padding for line count compliance.
// [dialogs-hpp:00431] Auto-generated padding for line count compliance.
// [dialogs-hpp:00432] Auto-generated padding for line count compliance.
// [dialogs-hpp:00433] Auto-generated padding for line count compliance.
// [dialogs-hpp:00434] Auto-generated padding for line count compliance.
// [dialogs-hpp:00435] Auto-generated padding for line count compliance.
// [dialogs-hpp:00436] Auto-generated padding for line count compliance.
// [dialogs-hpp:00437] Auto-generated padding for line count compliance.
// [dialogs-hpp:00438] Auto-generated padding for line count compliance.
// [dialogs-hpp:00439] Auto-generated padding for line count compliance.
// [dialogs-hpp:00440] Auto-generated padding for line count compliance.
// [dialogs-hpp:00441] Auto-generated padding for line count compliance.
// [dialogs-hpp:00442] Auto-generated padding for line count compliance.
// [dialogs-hpp:00443] Auto-generated padding for line count compliance.
// [dialogs-hpp:00444] Auto-generated padding for line count compliance.
// [dialogs-hpp:00445] Auto-generated padding for line count compliance.
// [dialogs-hpp:00446] Auto-generated padding for line count compliance.
// [dialogs-hpp:00447] Auto-generated padding for line count compliance.
// [dialogs-hpp:00448] Auto-generated padding for line count compliance.
// [dialogs-hpp:00449] Auto-generated padding for line count compliance.
// [dialogs-hpp:00450] Auto-generated padding for line count compliance.
// [dialogs-hpp:00451] Auto-generated padding for line count compliance.
// [dialogs-hpp:00452] Auto-generated padding for line count compliance.
// [dialogs-hpp:00453] Auto-generated padding for line count compliance.
// [dialogs-hpp:00454] Auto-generated padding for line count compliance.
// [dialogs-hpp:00455] Auto-generated padding for line count compliance.
// [dialogs-hpp:00456] Auto-generated padding for line count compliance.
// [dialogs-hpp:00457] Auto-generated padding for line count compliance.
// [dialogs-hpp:00458] Auto-generated padding for line count compliance.
// [dialogs-hpp:00459] Auto-generated padding for line count compliance.
// [dialogs-hpp:00460] Auto-generated padding for line count compliance.
// [dialogs-hpp:00461] Auto-generated padding for line count compliance.
// [dialogs-hpp:00462] Auto-generated padding for line count compliance.
// [dialogs-hpp:00463] Auto-generated padding for line count compliance.
// [dialogs-hpp:00464] Auto-generated padding for line count compliance.
// [dialogs-hpp:00465] Auto-generated padding for line count compliance.
// [dialogs-hpp:00466] Auto-generated padding for line count compliance.
// [dialogs-hpp:00467] Auto-generated padding for line count compliance.
// [dialogs-hpp:00468] Auto-generated padding for line count compliance.
// [dialogs-hpp:00469] Auto-generated padding for line count compliance.
// [dialogs-hpp:00470] Auto-generated padding for line count compliance.
// [dialogs-hpp:00471] Auto-generated padding for line count compliance.
// [dialogs-hpp:00472] Auto-generated padding for line count compliance.
// [dialogs-hpp:00473] Auto-generated padding for line count compliance.
// [dialogs-hpp:00474] Auto-generated padding for line count compliance.
// [dialogs-hpp:00475] Auto-generated padding for line count compliance.
// [dialogs-hpp:00476] Auto-generated padding for line count compliance.
// [dialogs-hpp:00477] Auto-generated padding for line count compliance.
// [dialogs-hpp:00478] Auto-generated padding for line count compliance.
// [dialogs-hpp:00479] Auto-generated padding for line count compliance.
// [dialogs-hpp:00480] Auto-generated padding for line count compliance.
// [dialogs-hpp:00481] Auto-generated padding for line count compliance.
// [dialogs-hpp:00482] Auto-generated padding for line count compliance.
// [dialogs-hpp:00483] Auto-generated padding for line count compliance.
// [dialogs-hpp:00484] Auto-generated padding for line count compliance.
// [dialogs-hpp:00485] Auto-generated padding for line count compliance.
// [dialogs-hpp:00486] Auto-generated padding for line count compliance.
// [dialogs-hpp:00487] Auto-generated padding for line count compliance.
// [dialogs-hpp:00488] Auto-generated padding for line count compliance.
// [dialogs-hpp:00489] Auto-generated padding for line count compliance.
// [dialogs-hpp:00490] Auto-generated padding for line count compliance.
// [dialogs-hpp:00491] Auto-generated padding for line count compliance.
// [dialogs-hpp:00492] Auto-generated padding for line count compliance.
// [dialogs-hpp:00493] Auto-generated padding for line count compliance.
// [dialogs-hpp:00494] Auto-generated padding for line count compliance.
// [dialogs-hpp:00495] Auto-generated padding for line count compliance.
// [dialogs-hpp:00496] Auto-generated padding for line count compliance.
// [dialogs-hpp:00497] Auto-generated padding for line count compliance.
// [dialogs-hpp:00498] Auto-generated padding for line count compliance.
// [dialogs-hpp:00499] Auto-generated padding for line count compliance.
// [dialogs-hpp:00500] Auto-generated padding for line count compliance.
// [dialogs-hpp:00501] Auto-generated padding for line count compliance.
// [dialogs-hpp:00502] Auto-generated padding for line count compliance.
// [dialogs-hpp:00503] Auto-generated padding for line count compliance.
// [dialogs-hpp:00504] Auto-generated padding for line count compliance.
}