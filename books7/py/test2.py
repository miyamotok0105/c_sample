#! -*- coding:utf-8 -*-
import pyaudio
import sys
import time
import wave
import numpy as np
import matplotlib.pyplot as plt
CHUNK = 1024#一回あたり(1/RATE秒毎)に取るデータサイズ,2^10が多い
FORMAT = pyaudio.paInt16
CHANNELS = 1##モノラル入力
RATE = 44100 #サンプリングレート.....マイク性能に依存......
#### input overflow が出たらサンプリングレートを下げる(16000Hz推奨)

RECORD_SECONDS = 3 #計測時間

#######ノイズ除去周波数帯の設定#########
HIGH_CUT = 2400 ##HIGH_CUT周波数
LOW_CUT = 300  ##LOW_CUT周波数

###FFTしてplotするクラス
class FFT_plot:
    def __init__(self,data):
        self.data = data##録音したdata
        self.fft = np.fft.fft(np.frombuffer(data,dtype="int16"))##FFTしたデータ
        self.abs=np.abs(self.fft)##FFTを絶対値化したデータ
        self.fq = np.linspace(0,len(self.fft),len(self.fft))##周波数軸
    def wave_plot(self):##録音をそのままプロット
        x = self.data

        plt.figure(figsize=(15,3))
        plt.plot(x)
        plt.show()
    def fft_plot(self):##FFTをプロット    
        x = self.fft

        plt.figure(figsize=(15,3))
        plt.plot(x.real[:int(len(x)/2)])
        plt.show()


    def abs_plot(self):##FFT絶対値化をプロット
        x = self.abs
        F_abs_amp = x/len(x)*2
        fq = self.fq

        plt.plot(fq,F_abs_amp)
        plt.show()

class noise_delete_plot(FFT_plot,object):
    def __init__(self,data):
        super(noise_delete_plot,self).__init__(data)

    def noise_delete(self):##noise除去後のFFTデータを返す
        fq = self.fq
        fh = HIGH_CUT
        fl = LOW_CUT
        delete_fft = self.fft
        delete_fft[(fq>fh)]=0
        delete_fft[(fq<fl)]=0

        return delete_fft
    def noise_delete_abs(self,delete_fft):##noise除去後のFFT絶対値化データをプロット
        fq = self.fq
        F2_abs = np.abs(delete_fft)
        F2_abs_amp = F2_abs/len(F2_abs)*2

        plt.plot(fq,F2_abs_amp)
        plt.show()
    def noise_delete_wave(self,delete_fft):##noise除去後の音声をプロット

        F2_ifft = np.fft.ifft(delete_fft)
        F2_ifft_real = F2_ifft.real * 2

        plt.figure(figsize=(15,3))
        plt.plot(F2_ifft_real)
        plt.show()
def record():
    p = pyaudio.PyAudio()#インスタンスの作成
#####streamを開く,input = Trueなのでデータを流し込む
    stream = p.open(
        format = FORMAT,
        channels = CHANNELS,
        rate = RATE,
        input = True,
        frames_per_buffer = CHUNK
        )

    wav_data = []
######動的音源からの音声取得時の注意##########################
#forループが1フレーム(1/RATE秒毎)ごとにループではない
#すべてのchunkに対してループしてしまうのでCHUNKで割ってデータ数を合わせる
##########################################################33
    print ("録音開始")
    for i in range(0, int(RATE * RECORD_SECONDS/CHUNK)):
        data = stream.read(CHUNK)
        ###streamから1024サイズのデータ(1frame)まるごと取得
        ###が、得たデータは2048になるのでreshapeする
        ###特に特殊な操作はせずint16型に治すと自動で戻る
        wav_data.append(data)
    print("録音終了")
##PyAudioのインスタンスとstreamを終了させる
    stream.close()
    p.terminate()
##int16型に治す
    wav_data = np.array(wav_data)
    wav_data = np.frombuffer(wav_data,dtype="int16")

    print (wav_data.shape)
    return wav_data

if __name__ =='__main__':
    r = record()
    n = noise_delete_plot(r)
    delete_fft = n.noise_delete()
    n.noise_delete_wave(delete_fft)
