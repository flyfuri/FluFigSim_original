object Form2: TForm2
  Left = 149
  Top = 0
  Width = 706
  Height = 738
  Caption = 'FluFigSim 3D-Animation'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001001010100000000000280100001600000028000000100000002000
    00000100040000000000C0000000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFCC
    CFCFCFCFCFFFFFFFCFCFCFCFCFFFFFCCCFCFCCCCCFFFFFCFFFFFFFFFFFFFFFCC
    CFCFFFFFFFCCFFFFFFFFFFFFFFFCCFFCFCCCFCFFCFCCCCFCFCFCFCCFCFCCCFFC
    FCFCFCFFFFFFCCFCFFFFFCCFCFFFFFFFFFFFFFFFFFFF99FFFFFFFFFFFF99F999
    9FFFFFF9999FFFF9999999999FFFFFFFF999999FFFFFFFFFFFFFFFFFFFFF0000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LabelZeitlupe: TLabel
    Left = 40
    Top = 160
    Width = 68
    Height = 13
    Caption = 'fache Zeitlupe'
  end
  object LabelBldpsek: TLabel
    Left = 40
    Top = 208
    Width = 39
    Height = 13
    Caption = 'Bilder/s:'
  end
  object LabelSpeed: TLabel
    Left = 16
    Top = 160
    Width = 6
    Height = 13
    Caption = '1'
  end
  object LabelBldrate: TLabel
    Left = 16
    Top = 208
    Width = 12
    Height = 13
    Caption = '25'
  end
  object GroupBoxSimZeit: TGroupBox
    Left = 8
    Top = 568
    Width = 113
    Height = 50
    Caption = 'Simulations-Zeit [s:ms]'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    object LabelSimSek: TLabel
      Left = 16
      Top = 16
      Width = 20
      Height = 24
      Caption = '00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabelSimMili: TLabel
      Left = 48
      Top = 16
      Width = 30
      Height = 24
      Caption = '000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabelDPunkt1: TLabel
      Left = 40
      Top = 16
      Width = 5
      Height = 24
      Caption = ':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
  object OpenGLPanel1: TOpenGLPanel
    Left = 216
    Top = 8
    Width = 265
    Height = 201
    TabOrder = 0
    PFDFlags = [f_PFD_DRAW_TO_WINDOW, f_PFD_SUPPORT_OPENGL, f_PFD_DOUBLEBUFFER]
    Font3D_Type.Charset = ANSI_CHARSET
    Font3D_Type.Color = clWindowText
    Font3D_Type.Height = -9
    Font3D_Type.Name = 'Arial'
    Font3D_Type.Style = []
    Font3D_Extrustion = 0.100000001490116
    Font2D_Type.Charset = ANSI_CHARSET
    Font2D_Type.Color = clWindowText
    Font2D_Type.Height = -9
    Font2D_Type.Name = 'Arial'
    Font2D_Type.Style = []
    OnInit = OpenGLPanel1Init
    OnPaint = OpenGLPanel1Paint
  end
  object ScrollBarSpeed: TScrollBar
    Left = 8
    Top = 176
    Width = 112
    Height = 16
    Max = 10
    Min = 1
    PageSize = 0
    Position = 1
    TabOrder = 1
    OnChange = ScrollBarSpeedChange
  end
  object ScrollBarBildrate: TScrollBar
    Left = 8
    Top = 224
    Width = 112
    Height = 16
    Max = 25
    Min = 10
    PageSize = 0
    Position = 25
    TabOrder = 2
    OnChange = ScrollBarBildrateChange
  end
  object ButtonPlay: TButton
    Left = 8
    Top = 56
    Width = 113
    Height = 25
    Caption = 'Play'
    TabOrder = 3
    OnClick = ButtonPlayClick
  end
  object ButtonStop: TButton
    Left = 8
    Top = 120
    Width = 113
    Height = 25
    Caption = 'Stop'
    Enabled = False
    TabOrder = 4
    OnClick = ButtonStopClick
  end
  object ButtonDauerPlay: TButton
    Left = 8
    Top = 88
    Width = 113
    Height = 25
    Caption = 'DauerPlay'
    TabOrder = 6
    OnClick = ButtonDauerPlayClick
  end
  object GroupBoxEchtz: TGroupBox
    Left = 8
    Top = 624
    Width = 113
    Height = 50
    Caption = 'Echt-Zeit [s:ms]'
    TabOrder = 7
    Visible = False
    object LabelEchtMili: TLabel
      Left = 48
      Top = 16
      Width = 30
      Height = 24
      Caption = '000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabelDPunkt2: TLabel
      Left = 40
      Top = 14
      Width = 5
      Height = 24
      Caption = ':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object LabelEchtSek: TLabel
      Left = 16
      Top = 16
      Width = 20
      Height = 24
      Caption = '00'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 248
    Width = 113
    Height = 73
    Caption = 'Achsen:'
    TabOrder = 8
    object CheckBoxHoch: TCheckBox
      Left = 8
      Top = 48
      Width = 97
      Height = 17
      Caption = 'Hochachse'
      TabOrder = 0
    end
    object CheckBoxLang: TCheckBox
      Left = 8
      Top = 32
      Width = 97
      Height = 17
      Caption = 'Laengsachse'
      TabOrder = 1
    end
    object CheckBoxQuer: TCheckBox
      Left = 8
      Top = 16
      Width = 97
      Height = 17
      Caption = 'Querachse'
      TabOrder = 2
    end
  end
  object GroupBoxKamF: TGroupBox
    Left = 8
    Top = 328
    Width = 113
    Height = 57
    Caption = 'Kamera-Führung:'
    TabOrder = 9
    object RadioButtonKamAut: TRadioButton
      Left = 8
      Top = 32
      Width = 65
      Height = 17
      Caption = 'Auto'
      TabOrder = 0
      OnClick = RadioButtonKamAutClick
    end
    object RadioButtonKamMan: TRadioButton
      Left = 8
      Top = 16
      Width = 73
      Height = 17
      Caption = 'Manuel'
      Checked = True
      TabOrder = 1
      TabStop = True
      OnClick = RadioButtonKamManClick
    end
  end
  object GroupBoxKam: TGroupBox
    Left = 8
    Top = 392
    Width = 113
    Height = 169
    Caption = 'Kamera:'
    TabOrder = 10
    object ButtonUP: TButton
      Left = 40
      Top = 16
      Width = 33
      Height = 33
      Caption = 'UP'
      TabOrder = 0
      OnMouseDown = ButtonUPMouseDown
      OnMouseUp = ButtonUPMouseUp
    end
    object ButtonRight: TButton
      Left = 72
      Top = 48
      Width = 33
      Height = 33
      Caption = '>>'
      TabOrder = 1
      OnMouseDown = ButtonRightMouseDown
      OnMouseUp = ButtonRightMouseUp
    end
    object ButtonLeft: TButton
      Left = 8
      Top = 48
      Width = 33
      Height = 33
      Caption = '<<'
      TabOrder = 2
      OnMouseDown = ButtonLeftMouseDown
      OnMouseUp = ButtonLeftMouseUp
    end
    object ButtonDown: TButton
      Left = 40
      Top = 80
      Width = 33
      Height = 33
      Caption = 'Down'
      TabOrder = 3
      OnMouseDown = ButtonDownMouseDown
      OnMouseUp = ButtonDownMouseUp
    end
    object ButtonZoomIn: TButton
      Left = 8
      Top = 120
      Width = 49
      Height = 41
      Caption = 'ZoomIn'
      TabOrder = 4
      OnMouseDown = ButtonZoomInMouseDown
      OnMouseUp = ButtonZoomInMouseUp
    end
    object ButtonZoomOut: TButton
      Left = 56
      Top = 120
      Width = 51
      Height = 41
      Caption = 'ZoomOut'
      TabOrder = 5
      OnMouseDown = ButtonZoomOutMouseDown
      OnMouseUp = ButtonZoomOutMouseUp
    end
  end
  object ButtonEditor: TButton
    Left = 8
    Top = 16
    Width = 113
    Height = 25
    Caption = 'Zurück zum Editor'
    TabOrder = 11
    OnClick = ButtonEditorClick
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 40
    OnTimer = Timer1Timer
    Left = 608
    Top = 8
  end
end
