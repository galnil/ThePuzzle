%!PS-Adobe-3.0
%%Creator: (ImageMagick)
%%Title: (re)
%%CreationDate: (2017-12-05T17:12:42+02:00)
%%BoundingBox: 1438 624 1465 652
%%HiResBoundingBox: 1438 624 1465 652
%%DocumentData: Clean7Bit
%%LanguageLevel: 1
%%Orientation: Portrait
%%PageOrder: Ascend
%%Pages: 1
%%EndComments

%%BeginDefaults
%%EndDefaults

%%BeginProlog
%
% Display a color image.  The image is displayed in color on
% Postscript viewers or printers that support color, otherwise
% it is displayed as grayscale.
%
/DirectClassPacket
{
  %
  % Get a DirectClass packet.
  %
  % Parameters:
  %   red.
  %   green.
  %   blue.
  %   length: number of pixels minus one of this color (optional).
  %
  currentfile color_packet readhexstring pop pop
  compression 0 eq
  {
    /number_pixels 3 def
  }
  {
    currentfile byte readhexstring pop 0 get
    /number_pixels exch 1 add 3 mul def
  } ifelse
  0 3 number_pixels 1 sub
  {
    pixels exch color_packet putinterval
  } for
  pixels 0 number_pixels getinterval
} bind def

/DirectClassImage
{
  %
  % Display a DirectClass image.
  %
  systemdict /colorimage known
  {
    columns rows 8
    [
      columns 0 0
      rows neg 0 rows
    ]
    { DirectClassPacket } false 3 colorimage
  }
  {
    %
    % No colorimage operator;  convert to grayscale.
    %
    columns rows 8
    [
      columns 0 0
      rows neg 0 rows
    ]
    { GrayDirectClassPacket } image
  } ifelse
} bind def

/GrayDirectClassPacket
{
  %
  % Get a DirectClass packet;  convert to grayscale.
  %
  % Parameters:
  %   red
  %   green
  %   blue
  %   length: number of pixels minus one of this color (optional).
  %
  currentfile color_packet readhexstring pop pop
  color_packet 0 get 0.299 mul
  color_packet 1 get 0.587 mul add
  color_packet 2 get 0.114 mul add
  cvi
  /gray_packet exch def
  compression 0 eq
  {
    /number_pixels 1 def
  }
  {
    currentfile byte readhexstring pop 0 get
    /number_pixels exch 1 add def
  } ifelse
  0 1 number_pixels 1 sub
  {
    pixels exch gray_packet put
  } for
  pixels 0 number_pixels getinterval
} bind def

/GrayPseudoClassPacket
{
  %
  % Get a PseudoClass packet;  convert to grayscale.
  %
  % Parameters:
  %   index: index into the colormap.
  %   length: number of pixels minus one of this color (optional).
  %
  currentfile byte readhexstring pop 0 get
  /offset exch 3 mul def
  /color_packet colormap offset 3 getinterval def
  color_packet 0 get 0.299 mul
  color_packet 1 get 0.587 mul add
  color_packet 2 get 0.114 mul add
  cvi
  /gray_packet exch def
  compression 0 eq
  {
    /number_pixels 1 def
  }
  {
    currentfile byte readhexstring pop 0 get
    /number_pixels exch 1 add def
  } ifelse
  0 1 number_pixels 1 sub
  {
    pixels exch gray_packet put
  } for
  pixels 0 number_pixels getinterval
} bind def

/PseudoClassPacket
{
  %
  % Get a PseudoClass packet.
  %
  % Parameters:
  %   index: index into the colormap.
  %   length: number of pixels minus one of this color (optional).
  %
  currentfile byte readhexstring pop 0 get
  /offset exch 3 mul def
  /color_packet colormap offset 3 getinterval def
  compression 0 eq
  {
    /number_pixels 3 def
  }
  {
    currentfile byte readhexstring pop 0 get
    /number_pixels exch 1 add 3 mul def
  } ifelse
  0 3 number_pixels 1 sub
  {
    pixels exch color_packet putinterval
  } for
  pixels 0 number_pixels getinterval
} bind def

/PseudoClassImage
{
  %
  % Display a PseudoClass image.
  %
  % Parameters:
  %   class: 0-PseudoClass or 1-Grayscale.
  %
  currentfile buffer readline pop
  token pop /class exch def pop
  class 0 gt
  {
    currentfile buffer readline pop
    token pop /depth exch def pop
    /grays columns 8 add depth sub depth mul 8 idiv string def
    columns rows depth
    [
      columns 0 0
      rows neg 0 rows
    ]
    { currentfile grays readhexstring pop } image
  }
  {
    %
    % Parameters:
    %   colors: number of colors in the colormap.
    %   colormap: red, green, blue color packets.
    %
    currentfile buffer readline pop
    token pop /colors exch def pop
    /colors colors 3 mul def
    /colormap colors string def
    currentfile colormap readhexstring pop pop
    systemdict /colorimage known
    {
      columns rows 8
      [
        columns 0 0
        rows neg 0 rows
      ]
      { PseudoClassPacket } false 3 colorimage
    }
    {
      %
      % No colorimage operator;  convert to grayscale.
      %
      columns rows 8
      [
        columns 0 0
        rows neg 0 rows
      ]
      { GrayPseudoClassPacket } image
    } ifelse
  } ifelse
} bind def

/DisplayImage
{
  %
  % Display a DirectClass or PseudoClass image.
  %
  % Parameters:
  %   x & y translation.
  %   x & y scale.
  %   label pointsize.
  %   image label.
  %   image columns & rows.
  %   class: 0-DirectClass or 1-PseudoClass.
  %   compression: 0-none or 1-RunlengthEncoded.
  %   hex color packets.
  %
  gsave
  /buffer 512 string def
  /byte 1 string def
  /color_packet 3 string def
  /pixels 768 string def

  currentfile buffer readline pop
  token pop /x exch def
  token pop /y exch def pop
  x y translate
  currentfile buffer readline pop
  token pop /x exch def
  token pop /y exch def pop
  currentfile buffer readline pop
  token pop /pointsize exch def pop
  /Times-Roman findfont pointsize scalefont setfont
  x y scale
  currentfile buffer readline pop
  token pop /columns exch def
  token pop /rows exch def pop
  currentfile buffer readline pop
  token pop /class exch def pop
  currentfile buffer readline pop
  token pop /compression exch def pop
  class 0 gt { PseudoClassImage } { DirectClassImage } ifelse
  grestore
  showpage
} bind def
%%EndProlog
%%Page:  1 1
%%PageBoundingBox: 1438 624 1465 652
DisplayImage
1438 624
27 28
12
27 28
0
0
02343B02343B02343B02343B02343B02343B02343B02343B02343B02343B02343B02343B02343B
02343B02343B02343B02343B02343B02343B02343B02343B02343B02343B02343B02343B02343B
02343B02343AFDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5
FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5FDCBC5
FDCBC5FDCBC502333AFDCCC502333A02333A02333A02333A02333A02333A02333A02333A02333A
02333A02333A02333A02333A02333A02333A02333A02333A02333A02333A02333A02333A02333A
02333A02333AFDCCC502333AFDCCC502333A02333A02333A02333A02333A02333A02333A02333A
02333A02333A02333A02333A02333A02333A02333A02333A02333A02333A02333A02333A02333A
02333A02333A02333AFDCCC5023339FDCCC6023339023339023339023339023339023339023339
023339023339023339023339023339023339023339023339023339023339023339023339023339
023339023339023339023339FDCCC6023239FDCDC6023239023239023239023239023239023239
023239023239023239023239023239023239023239023239023239023239023239023239023239
023239023239023239023239023239FDCDC6023238FDCDC7023238023238023238023238023238
023238023238023238023238023238023238023238023238023238023238023238023238023238
023238023238023238023238023238023238FDCDC7023138FDCEC7023138023138023138023138
023138023138023138023138023138023138023138023138023138023138023138023138023138
023138023138023138023138023138023138023138FDCEC7023137FDCEC8023137023137023137
023137023137023137023137023137023137023137023137023137023137023137023137023137
023137023137023137023137023137023137023137023137FDCEC8023036FDCFC9023036023036
023036023036023036023036023036023036023036023036023036023036023036023036023036
023036023036023036023036023036023036023036023036023036FDCFC9023036FDCFC9023036
023036023036023036023036023036023036023036023036023036023036023036023036023036
023036023036023036023036023036023036023036023036023036023036FDCFC9022F35FDD0CA
022F35022F35022F35022F35022F35022F35022F35022F35022F35022F35022F35022F35022F35
022F35022F35022F35022F35022F35022F35022F35022F35022F35022F35022F35FDD0CA022E34
FDD1CB022E34022E34022E34022E34022E34022E34022E34022E34022E34022E34022E34022E34
022E34022E34022E34022E34022E34022E34022E34022E34022E34022E34022E34022E34FDD1CB
022D33FDD2CC022D33022D33022D33022D33022D33022D33022D33022D33022D33022D33022D33
022D33022D33022D33022D33022D33022D33022D33022D33022D33022D33022D33022D33022D33
FDD2CC022D32FDD2CD022D32022D32022D32022D32022D32022D32022D32022D32022D32022D32
022D32022D32022D32022D32022D32022D32022D32022D32022D32022D32022D32022D32022D32
022D32FDD2CD022C31FDD3CE022C31022C31022C31022C31022C31022C31022C31022C31022C31
022C31022C31022C31022C31022C31022C31022C31022C31022C31022C31022C31022C31022C31
022C31022C31FDD3CE022B30FDD4CF022B30022B30022B30022B30022B30022B30022B30022B30
022B30022B30022B30022B30022B30022B30022B30022B30022B30022B30022B30022B30022B30
022B30022B30022B30FDD4CF012A2FFED5D0012A2F012A2F012A2F012A2F012A2F012A2F012A2F
012A2F012A2F012A2F012A2F012A2F012A2F012A2F012A2F012A2F012A2F012A2F012A2F012A2F
012A2F012A2F012A2F012A2FFED5D0F1EEEC0E1113F1EEECF1EEECF1EEECF1EEECF1EEECF1EEEC
F1EEECF1EEECF1EEECF1EEECF1EEECF1EEECF1EEECF1EEECF1EEECF1EEECF1EEECF1EEECF1EEEC
F1EEECF1EEECF1EEECF1EEECF1EEEC0E1113FAFAF8050507FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8
FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8
FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8FAFAF8050507F6F5F3090A0CF6F5F3F6F5F3F6F5F3F6F5F3
F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3
F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3F6F5F3090A0CF6F4F1090B0EF6F4F1F6F4F1F6F4F1
F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1
F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1F6F4F1090B0EF5F3F00A0C0FF5F3F0F5F3F0
F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0
F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F0F5F3F00A0C0FF4F2EF0B0D10F4F2EF
F4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EF
F4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EFF4F2EF0B0D10F3F0ED0C0F12
F3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0ED
F3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0EDF3F0ED0C0F12F2EFEC
0D1013F2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFEC
F2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFECF2EFEC0D1013
F3E5D4001018F1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEA
F1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEAF1EEEA
0E11155D71A0201B28211813151B20151B20151B20151B20111A220016310111190F12160F1216
0F12160F12160F12160F12160F12160F12160F12160F12160F12160F12160F12160F12160F1216
0F1216F0EDE9

%%PageTrailer
%%Trailer
%%EOF
