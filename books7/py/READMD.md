

任意のSignal-to-Noise比の音声波形をPythonで作ろう！
https://engineering.linecorp.com/ja/blog/voice-waveform-arbitrary-signal-to-noise-ratio-python/

データセット
http://staff.ustc.edu.cn/~jundu/The%20team/yongxu/demo/SE_DNN_taslp.html

```
python create_noisy_minumum_code.py --clean_file ./womanvoice.wav --noise_file ./0_Mix_White.wav --output_clean_file ./womanvoice_clean.wav --output_noise_file ./womanvoice_noise.wav  --output_noisy_file ./womanvoice_noisy.wav --snr 0
```



```
python create_mixed_audio_file.py --clean_file ./womanvoice.wav --noise_file ./0_Mix_White.wav --snr 0 --output_mixed_file ./out.wav
```
