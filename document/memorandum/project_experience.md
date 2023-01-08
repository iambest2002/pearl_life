@[TOC]

#### O 21  : reuse these code for trian 
R : 

D : 

Firstly, We train our model and found gpu is not enough. It make a error ref : https://github.com/pytorch/pytorch/issues/21819, and our ubuntu system always reboot. So decide to make video code into https://www.kaggle.com/pengliu1997/paper/edit.  We make 3DCNN to show result.


####  O7 : reubild masterpaper

R :

D : 
摘要部分： done 
-  这部分的撰写是有一个严格的基础
-  框架： 情感识别是什么有什么用；  情感识别的常用方法和问题；我们的方法基本方式; 自己方法是如何解决这个问题的；  实验过程和结果；


介绍部分：  done, 需要让人看一遍。 
-  第一章的撰写各种毕业论文的撰写方式都不一样， 其实对于毕业论文， 第一章和第二章的内容主要就是要把自己方法怎么做的介绍清楚（最好说一下国内外研究现状）、研究的目的和意义、问题再描述一遍、自己怎么解决的再说一下（这里和摘要部分的区别是详细而且不能带后续的数据结果， 只能从原理上解释）。  之后对本文的工作做一个介绍。  over。  所以这里第一章我的打算按照小论文的写作方式， 介绍一下研究是啥和有啥意义 + 研究现状 + 本文的目的和文章结构
- 框架 ： 
- + 研究意义和情感识别背景部分 ：介绍一下研究情感识别的作用和一些历史背景。 其实这里的背景不算真正的背景， 大部分背景是关于政策的或者宏观的，  但是我这里简单提出一下当前深度学习的背景、情感识别的背景 。 然后再说一些研究的意义。done 
- + 情感识别的定义 ： 说一下当前的情感识别的学派， 我们是基于分类模型下的研究。 done, 但是这部分会有分类的查重问题和图需要自己画
- + 国内外研究现状 ：其实可以不用分国内外， 而是直接调研过去的相关工作， 确定方法。  就分开说， 说三种模态现在都采用了什么方法。 
- + 本文的主要工作 + 文章结构： 说一下前面工作的问题， 本文怎么解决。 注意这里面不要带实验结果，因为不是摘要。  最后说一下本文的文章结构。  

基础理论 ： done , 自己已经检查了一遍。 图画的有点丑
-  第二章的撰写是比较难的， 由于老师要求前两章不要灌水， 只能吧一些内容往后面移动了。 主要想说一下深度学习基础、音频、视觉、音视频情感识别的基本方法。 
- + 深度学习理论： 介绍了深度学习的基本单元组成结构和误差反向传播的过程。
- + 多模态融合baseline : 介绍了三种融合策略的细节， 并且给出自己的评价。 

单模态部分： 
- 这部分内容本来是想分为语音和视觉两部分的， 但是之前增老师觉得这样写会让论文的章节比较多， 这样会显得每一章的工作量不多。因此这里我把单模态语音和视频两个全部放到了一起。 并且加了数据集的介绍与选择， 这样可以搭配到一起。 
- + 数据集 + 实验规则： 介绍了当前自己用的数据集， 并介绍了实验条件和约束。 
- + 语音情感识别：  介绍一些语音预处理的方式、 特征提取的方式（参照https://blog.csdn.net/qq_28006327/article/details/59129110）然后就介绍了自己的方法。 之后开始做实验， 实验参照 https://www.kaggle.com/pengliu1997/parallel-2d-cnn-attention-lstm-pytorch-95-4-acc/edit/run/45310325 工作开始进行迭代， 需要去看一下如何切换网络， 然后开始训练，得出结果后进行分析。  注意这里面噪声实验非常多， 需要仔细搞。 
- + 视觉情感识别：





python main_msaf.py --datadir ./preprocessed/preprocessed/    --k_fold 2    --epochs 5  --checkpointdir ./checkpoints/checkpoints/ --train
new : 
| method |result | comment|
|--|--|--|
| 1DCNN + pertrain + no noise|  epoch 30 :64.7% |  |
| rsnet  + pertrain + no noise|  epoch 30 :64.7% |  |





| method |result | comment|
|--|--|--|
| 1DCNN + 3DCNN +  multimap + all pertrian +  no noise| 75%  |  init  method|
| 1DCNN + 3DCNN + attention  + all pertrian + no noise| epoch 30 : 76.7%  |  cfn  method|
| 1DCNN + 3DCNN + later fusion  + all pertrian + no noise| maybe 70%  | maybe attention fusion is bully shit? |
|  1DCNN + 3DCNN + attention  +not pertrain | 48% |   |
|  1DCNN + 3DCNN + attention  + video  pertrain | 70% |   |
|  1DCNN + 3DCNN + attention  + audio  pertrain | 66% | if one model is pertrian, the result will be good. if video is pertrian, the acc is 70%. If audio is pertrai, the acc is 66%. It may been network cann't control train direction both two model, just one model is ok.   |
| 1DCNN + pertrain + no noise|  epoch 10 :82.8% |  This is amazing, what I was doing ?|
| 1DCNN + not pertrain + no noise|   epoch 20 : 43%， epoch 30 : 46 %, epoch 50 : 46.1%  |  |
| rsnet + not pertrain + no noise|   epoch 20 : 51.6 % |  |
| rsnet + not pertrain +  noise|   epoch 20 :51.67%， epoch 80 : 58.2%  |  |
|  rsnet + not pertrain + no noise| 48% |  code save into memorandum ：rsnet |
| 1DCNN + pertrain +  noise|  epoch 20 :87 % |audio pertrain model 1DCNN overfit very much, Please not using this to train. And noise is work. |
| 1DCNN + not pertrain + noise|   epoch 20:  44.39% |  It is down 3 % that not noise  |
|  rsnet + not pertrain +  noise| % |   |
|  3DCNN + pertrian | epoch 5: 67%  |  |
|  3DCNN + not pertrian |  24%|  |
| rsnet + 3DCNN + add  + not pertrian + not noise| 48%  |  key example|
| rsnet + 3DCNN + add  + video pertrian + not noise| 70%  |  key example|
| rsnet + 3DCNN + add  + video pertrian +  noise| epoch 30 : 72%  |   what |
| rsnet + 3DCNN + add  + video pertrian +  not noise| epoch 10: 70% , epoch 20 :71 % |  |
|  1DCNN + 3DCNN + attention  +video  pertrain + noise| peoch 80 : 75.7 % |   |
| rsnet + 3DCNN + pool  + video pertrian + not noise| epoch 5 : 42%  |   ddd|
|  1DCNN + 3DCNN + pool  + video  pertrain | % |    |
|   |  |  |
|   |  |  |
|   |  |  |
# preface
we want to record my whole work into this markdown. as we know some project is not easy to reuse. We aim to achieve reused and effective. So we define a big project into these rule.  we using #### O* to represent small step in whole work.  ### O* represent  our noise data.  ## O is whole object  as project. In every step , we using R mean this object result; using D to describe detail in object achieve. in detail,  some problem often happened, we need add question(Q) into detail to explain how we solve it. 

# content 

## O : finish my whole master paper.
### O1 : make my soft-resnet recognition model has a preference  in noise audio data.
#### O1 : please make sure keras and tensorflow version and not conflict
 R :  ok , using latest version  keras and tensorflow, also we need cudnn and tookit. 


#### O2 : carry kaagle code  into my local computer and create  conda environment running ok . 
R :  done   
D :here is some install commands.
```shell
conda create  -n tfboy python=3.7
conda activate tfboy

pip install pandas
pip install seaborn
pip install numba==0.48
pip install librosa  
conda install keras-gpu 
conda install cudnn    // this will not been install due conda think your will been install in windows, but we not. 

 conda install -c conda-forge --name tfboy ipykernel -y   // install ipynb to use 
```


- Q : when building this system, I need to test wether gpu  is working 、 
```python
import tensorflow as tf
physical_device = tf.config.experimental.list_physical_devices('GPU')
print(f'Device found : {physical_device}') 
```
- Q : when I need to push this project , it has many train data in git. I create a .gitignore file in the root dir and add *.wav to filter this kind of files.  ref : [1]

####  O3 : try to change the code make the deep learning input is mel.  
R : yes , the acc is 68 in 100 epoches.   the acc maybe 64
D  we using a public code directly to run into self environment. that is right to run. 
 - Q :  ImportError: cannot import name 'plot_model' from 'keras.utils'  please ref 2.

#### O4 : make keras benchmark model into cifar10 dataset. 
R : we using a demo1.py to run， but we have not change data as audio and we jest using * 3 , not get into * 1.
D : In the detail, we refer some blog but it is not work. So we using https://github.com/qubvel/classification_models demo code without input, and then we refer  https://keras.io/zh/examples/cifar10_resnet/ how to  make cifar10 as input data. Then we make it together. In the coding time , we get error (module ‘keras.utils‘ has no attribute ‘to_categorical‘ ) , refer https://blog.csdn.net/MSJ_nb/article/details/117462928 to solve it.  the code as follow.
```python
import keras
from classification_models.keras import Classifiers
from keras.datasets import cifar10
ResNet18, preprocess_input = Classifiers.get('seresnet18')
from keras.utils import np_utils
# prepare your data


(X, Y), (X_test, y_test) = cifar10.load_data()
X = preprocess_input(X)

n_classes = 10

Y = np_utils.to_categorical(Y, n_classes)
y_test = np_utils.to_categorical(y_test, n_classes)

# build model
base_model = ResNet18(input_shape=(32,32,3), include_top=False)
x = keras.layers.GlobalAveragePooling2D()(base_model.output)
output = keras.layers.Dense(n_classes, activation='softmax')(x)
model = keras.models.Model(inputs=[base_model.input], outputs=[output])

# train
model.compile(optimizer='SGD', loss='categorical_crossentropy', metrics=['accuracy'])


model.fit(X, Y, batch_size=32, epochs=5, validation_data=(X_test, y_test)) 
```

#### O5 : make keras benchmark model into our audio data.
R : ok , we reduce data augment from O3, and make input is 128 * 384. The acc is 71, same acc. 
D : 


#### O6 : make soft-noise model into our data 
R :    ok , but the result is very bad.  I found many multi- modal not focus on audio, just using sample model, So add noise data into audio framework is useful but not anyone do it.

D : soft noise work had been run in cifair-10,  so we just change input as our work is fine. but the result is very bad. So I try to using another multi model code. I find a lot of code. First, I find some database were used in emotion recognition. Like RAVEE、IEMCOP、MELD and soon on. RAVEE is small dataset. the current accuracy is 70- 74%. IENCOP is bigger and has many video face lam data, the acc is 70-73% also.  MELD is more bigger, but acc is not well,just 50% due it come from daily show without pretend  and conversion emotion is not common emotion recognition, need content.  After we get some database situation, we need to running some code. 
-  Firstly,  I ref https://github.com/Samarth-Tripathi/IEMOCAP-Emotion-Detection but not run, I plan run it if necessary. 
-  Nextly, I ref https://github.com/ankurbhatia24/MULTIMODAL-EMOTION-RECOGNITION to run code in database MELD, the result is not good and the author just 43%, the good thing is it can run baseline, but the worse thing is acc is not good enough and without real model and data process code about paper.The baseline can ref https://drive.google.com/drive/folders/12ASDScVn2cCmgs_XWerQVgu1A9nAViGO?usp=sharing.   


- Nextly, I try to find  RAVEE or IECOMP database paper, then I found code in paper with code, and then I find many codes were pytorch, it make me realize I don't to escare study new framework, it will waste many time in find recourse only in tensorflow.  So, I accept we need to learn pytroch. 
- Nextly, I found there have many multimodel dl were achieve in https://github.com/declare-lab/multimodal-deep-learning##meld-a-multimodal-multi-party-dataset-for-emotion-recognition-in-conversation, and some of paper using IEMCOP or RAVEE, and ref paper with code .  I find  bc-LSTM achieve 74 using keras and A + T + V
three models, it need to achieve in free time.  Many paper achieve in three model. I found https://github.com/skeletonnn/cfn-sr this paper achieve audio and visual two models, and after reading readme.md, I found the author ref https://github.com/anita-hu/MSAF, I found MSAF using RAVEE to do example but three model. whatever, I plan to run this code and download database about video and face-mark. 

TODO : 
1. I need to download database about video and face-mark. Running https://github.com/anita-hu/MSAF. 
2. running bc-LSTM code and know other fusion method in https://github.com/declare-lab/multimodal-deep-learning#Attention-based-multimodal-fusion-for-sentiment-analysis. 

#### O7 : download database about video and face-mark. Running [7]. 
R :    ok , the result is 71.97%

D :  Downing database is ok.   but I find it is hard to run in local machine due my system is window. So I buy a google store to use. And we need to learn torch for read code. This paper code has a lot probability can runnable. I run it and it is hug data and we need using pre-train model. So we need to  try this continue. the result is pretty good ,73%, by pertain model, but I want  to run it without pertain.  In running time, I get a error  : RuntimeError: view size is not compatible with input tensor's size and stride (at least one dimension spans across two contiguous subspaces) ......., we ref https://stackoverflow.com/questions/66750391/runtimeerror-view-size-is-not-compatible-with-input-tensors-size-and-stride-a  change view() to reshape() was ok. then I want to write a file content into a file : %%writefile main_utils.py + file content. We use this method change view() to reshape() and get finally test acc is 71.97% in kaggle. In training experience has a little thing  https://www.kaggle.com/general/195225 and   https://www.kaggle.com/general/195225 about gpu performance and   only read file permission. 


TODO : 
1. study pytorch  and make note in blog.  ok , the result can ref https://leopeng.blog.csdn.net/article/details/104330563 . 

#### O8 : run code in local windows

R :  just cpu is ok, gpu continue need  run. So, I need to change code into ubuntu. 

D :  I need to run code in local computer.  My local gpu is not have cuda so I want install cuda without conda. We download in :https://developer.nvidia.cn/cuda-downloads?target_os=Windows&target_arch=x86_64&target_version=10&target_type=exe_local and ref https://zhuanlan.zhihu.com/p/110332563 find my computer support 11+ version.  And we should know that nvidia cudatoolkit and cudnn same as conda cudnn and toolkit, but conda is small and dont need to install in local host ref :https://blog.csdn.net/qq_42406643/article/details/109545766. Default using conda's , if not exit , choosing local computer cuda ref :https://blog.csdn.net/qq_40947610/article/details/114707085. we install 11.5 but not working, ref    https://www.reddit.com/r/MachineLearning/comments/qka6p0/d_does_cuda_latest_version_support_all_version_of/. So we need another version, like 11,0 in kaggle.


#### O9 : load ubuntu and run code in local ubuntu.

R: OK, it is soved.

D : After failed to run code in wondows, I choose to rebuild my ubuntu system.  So,  using my USB to rebuild a new system. I choose normal model to load, but I got error with “grub installation failed”, please ref this: https://blog.csdn.net/qq_34544129/article/details/78363941. After system is loading, I install some public  software and install nvidia drive. But we I using "ubuntu-drivers devices 
sudo ubuntu-drivers autoinstall", the linux kernel is changed, so I need to reuse advantage configure recover init kernel. But  the nvidia is error to connect. I reinstall and reboot, It is work! But I don't know what I did, How it is workable.
- Nextly, I install some conda lib about pytorch. Please noting that we don't need to install Cuda by myself(ref:  https://blog.csdn.net/qq_36851515/article/details/107608967), the anaconda will install automatically. The GPU is work! Yes!, and I run  **python main_msaf.py --datadir ./preprocessed/preprocessed/    --k_fold 2    --epochs 5  --checkpointdir ./checkpoints/checkpoints/ --train**, it work beautifully.

#### O 10 : familiar  with  code [7][6]
R : maybe  had knowing  it.  I understand code[7] 70%, but unable to change.  

update : undsanding 85%[6][7] and able to change. 


D:  In the reading paper, I was wrecked. I do not know what is meaning of Split-Attention .  So I need to read a paper : ResNeSt: Split-Attention Networks. In the read time, I forgot the 1  * 1 convolution function, So I try to search it.  In this blog: https://blog.csdn.net/francislucien2017/article/details/86759871  said 1 * 1 is aiming to align dim to satisfy the requirement.  After that  I ref  [3,4,5, 7] to understand  SeNest、 ResNeXt. Then I start to reading codes again and find it is hard to read again.  Then I read  paper 6, finding that is easy to understand (Beside transform self-attention is not understanding), and many code ref [7]. So I need to run code again and re-read [7] to compare with [6]. 
- + data_preset: when we give data direction, we get every actor direction 's  mp4 files. Then we get this pwd actor landmark and  init a VideoProcessor class.  Then we using VideoProcessor.preprocess to extract data.  Finally, we using mfcc to extract audio feature. 
- +  main_msaf.py :   we data into it, we will create data_load to load. And we create model. In [6], it using audio  featrue as attention due it easy to deal and include time dim data. Then fusion it with video and give a K size weight by softmax, and multi video-self and add redisaul origin
data. In[7], the author using split attention [14] to fusion two kind of model data. 



In  [6],  we  can see that, the key point is atttention fusion. We using   [(2 , 7 , 7, 2048, 4)] video input and  [64, 4] dim audio input.  The author using audio y into transformer and cut end as  attention.  And using video make many linear layer to make  2048 to 64 for weight add. And remove 64 to zero for softmax to get every map weight (two data combine, name is all_spatial_attn_weights_softmax ). Finally, the video x[0] - x[3]  * every  all_spatial_attn_weights_softmax,  add  origin video  as output.


TODO : 
 1. understanding transforms self-attention.   ok
 2. understanding paper [7] work. 


####  O 11 : subwork : run code about audiovisual emotion project. 
R : OK, that deal but need add data, some picture need been added into paper.
#### O 12  : change code without pre-train
R : OK, if not pre-train , the acc will down from  72 % to  28% when epoch set 5,    42% when epoch set 10 ，from 79% to 45%.    46% when epoch is 70%.      it can been see that pre-trian is essential in deep leanring.

Q : what can we learn from this pertrain ?
if one model is pertrian, the result will be good. if video is pertrian, the acc is 70%. If audio is pertrai, the acc is 66%. It may been network cann't control train direction both two model, just one model is ok. 


D : remove this code from resouce can been without pre-train.
```python
        if args.train:  # load unimodal model weights
            video_model_path = os.path.join(args.checkpointdir,
                                            "resnext50/fold_{}_resnext50_best.pth".format(i + 1))
            video_model_checkpoint = torch.load(video_model_path) if use_cuda else \
                torch.load(video_model_path, map_location=torch.device('cpu'))
            video_model.load_state_dict(video_model_checkpoint)
            audio_model_path = os.path.join(args.checkpointdir,
                                            "mfccNet/fold_{}_mfccNet_best.pth".format(i + 1))
            audio_model_checkpoint = torch.load(audio_model_path) if use_cuda else \
                torch.load(audio_model_path, map_location=torch.device('cpu'))
            audio_model.load_state_dict(audio_model_checkpoint)
```
#### O 13  : using single-model to  train
R : OK.  the audio model  is ok , when epoch set 10 without pre-train, the acc is  43% and train speech is fast. 

 the video  model  is ok , when epoch set 10 without pre-train, the acc is  22% and train speech is  slow. 

D :  
1. For audio model, we need to remove  images file input, firstly.  Removing   MSAFNet and change multimodal_model to  audio_model.   Now it is ok, we name this code  file is  main_msaf single_audio.  The video single model is same rule, so we not to talk.
```python
def get_X(device, sample):
    images = sample["images"].to(device)
    images = images.permute(0, 2, 1, 3, 4)  # swap to be (N, C, D, H, W)
    mfcc = sample["mfcc"].to(device)
    n = images[0].size(0)
    return mfcc, n

```




#### O 14 : change code output  loss ，acc and matrix figure 
R :  ok ,  I got it.
D : 
1. we ref  https://blog.csdn.net/leviopku/article/details/108985530 to type  ``tensorboard --logdir=/home/liu/Downloads/MSAF-master/MSAF-master/ravdess/checkpoints/checkpoints/logs/fold2_20220106-212705`` to generate loss figure by tensorboard. But it is not able custom.     
2. we ref some blog to achieve  matrix like https://yanwei-liu.medium.com/calculate-confusion-matrix-and-per-class-accuracy-in-pytorch-571e31bf943b, but we see ``def validation(get_X, model, device, loss_func, val_loader, metric_topk, show_cm=True):`` has show_cm to display matrix.  We run it, but get error  about output. So I ref https://github.com/optuna/optuna/issues/1604 to add  ``all_y_pred = np.argmax(all_y_pred.cpu(),axis=1)``  sloved it. But it was just termial output, we need figure. So I ref  some code from  https://yanwei-liu.medium.com/calculate-confusion-matrix-and-per-class-accuracy-in-pytorch-571e31bf943b to save matrix as picture.  it was ok.
3. if  you want to add acc, Please using follow code in line 201 of msf_main.py
```python
print("acc" ,np.mean(k_score))
```

#### O 15 : change video model  to compare diff framework.
R :  ok , it is not easy to add, And the video is not essential in model. So, we just using 3D- Resnet.

#### O 16 : change audio code as rsnet model and make a compare in single and fusion.

R :  OK,  It improved. The acc  is 35%   when epoch is 5 without pre-train.   the acc  is  42%  when epoch is 10 without pre-train.  the acc  is  48%  when epoch is 20 without pre-train.    
Due fusion is hard to ref init code, we do a add as fusion,  the acc is 70%.



D : we want to add noise network as auido network, So we ref  [18] and https://github.com/weiaicunzai/pytorch-cifar100  to download many model resource code. It require me to download data and change code to residual shrinkage network. Finnally ,  it is successful. But, the question is dim is not suit,  we check  mfcc shape is [13, 212]by add code ``print(mfcc.shape)``. And checking  resdual get shape is [3，32，32]. So we need add one dim in mfcc. So we ref https://blog.csdn.net/itnerd/article/details/101564698 to make code as follow :
```python
def get_X(device, sample):
    images = sample["images"].to(device)
    images = images.permute(0, 2, 1, 3, 4)  # swap to be (N, C, D, H, W)
    mfcc = sample["mfcc"].to(device)
    n = images[0].size(0)
    #print(mfcc.shape)
    mfcc = mfcc.unsqueeze(1)
    #print(mfcc.shape)
    return mfcc, n
```
And then we copy rsnet pytorch version code into mfcc_cnn.py. And replace ``audio_model = MFCCNet()`` to  ``audio_model = mfcc_cnn.rsnet18()``. Then we need change input shape of rsnet in mfcc_cnn.py code  to make dim 3 to 1. Then, it is work. Finally, we add this audio method into fusion to test.   It is not easy to change our code. First, we need to add change input type as follow :
```python
# define model input
def get_X(device, sample):
    images = sample["images"].to(device)
    images = images.permute(0, 2, 1, 3, 4)  # swap to be (N, C, D, H, W)
    mfcc = sample["mfcc"].to(device)
    n = images[0].size(0)
    mfcc = mfcc.unsqueeze(1)
    return [images, mfcc], n
```
Then, we open video per-train. Beside that, we  change RSNet  num_calsses from 100 to 8. Finally,  we change our fusion class,  we remove  all ``make_blocks`` code, and just using single model to prection. Then , we got result to do a add fusion in forward to test.  The key code as follow and code had  saved in  msaf_ravdess rsnet_fuison.py.
```python 
    def forward(self, x):
        
            if hasattr(self, "video_id"):
                x[self.video_id] = self.video_model(x[self.video_id])
            if hasattr(self, "audio_id"):
                x[self.audio_id] = self.audio_model(x[self.audio_id])
            #print(x[0].shape)
            #print(x[1].shape)
            x = sum(x);
            #print(x.shape)
            #res = torch.cat(x, dim=0)  # concate data by x pix.  ref : https://pytorch.org/docs/stable/generated/torch.cat.html
            res = self.fc(x)                    
            return res    
   ```
the result is  when video is per-train.    In the change perhase, I met a lot question:
-  I don't understand how to used ModuleList or Sequential in forwad, Then, I ref https://www.codeleading.com/article/36642068773/   to got it.
-  In fusion code, I dont understand init code `` make_blocks``, it causes many problem. Firstly, I want to use  ``self.msaf_locations`` to locate fusion location. I ref https://blog.csdn.net/d14665/article/details/112218767  and https://blog.csdn.net/york1996/article/details/81949843 to change reshape in our forward code to layers. Then, I got many question in dim.  So, I decide to remove it, So I  ref    cfn-sr  code in github to adjust fusion layer , delete loop and  [i]. Finally,  I got it. 
-  The init code undstand  is not well, the author using ``make_blocks``  to create a ModuleList into i + 1 size 's list .   So we can forward layer by [i]. If we use [i] = 7, the video_model_blocks will forward to video layer [7]. Audio aslo same rule. We put  x[0] and x[1] into MSAF, it using many vardiny map and output ehance x[0] and origin x[1]. In finally loop,just using 7 -end, 11 -end.   Finally in we used sum to do a   later fusion.  The key code as follow :

```python

    def forward(self, x):
        for i in range(self.num_msaf + 1):
            if hasattr(self, "video_id"):
                x[self.video_id] = self.video_model_blocks[i](x[self.video_id])
            if hasattr(self, "audio_id"):
                x[self.audio_id] = self.audio_model_blocks[i](x[self.audio_id])
            if i < self.num_msaf:
                x = self.msaf[i](x)
                
        return sum(x)
```

#### O 17     add noise to verify whether effective. 
R : multitask is hard to add, so I just  to add  noise framework.  The result show that our framework can rise up   3%.  not so effective.


D :   I want to add white noise in to mfcc and add noise framework to filter this noise and make framework to been better.
ref this kaggle link [17], the add noise code as follow:
```python 
def noisy_signal(signal, snr_low=15, snr_high=30, nb_augmented=2):
    
    # Signal length
    signal_len = len(signal)

    # Generate White noise
    noise = np.random.normal(size=(nb_augmented, signal_len))
    
    # Compute signal and noise power
    s_power = np.sum((signal / (2.0 ** 15)) ** 2) / signal_len
    n_power = np.sum((noise / (2.0 ** 15)) ** 2, axis=1) / signal_len
    
    # Random SNR: Uniform [15, 30]
    snr = np.random.randint(snr_low, snr_high)
    
    # Compute K coeff for each noise
    K = np.sqrt((s_power / n_power) * 10 ** (- snr / 10))
    K = np.ones((signal_len, nb_augmented)) * K
    
    # Generate noisy signal
    return signal + K.T * noise
```
we just make librosad.load data into this function the noise audio MFCC  will been add.  before that , we need to know what mean in this function. I ref [19] to know what means and know snr is log (audio energy/  noise energy). If noise is huge, the snr will be negtive.   So snr_low and snr_high is snr randsourround. nb_augmented is amplitude, usual set 1 ref https://www.kite.com/python/answers/how-to-add-noise-to-a-signal-using-numpy-in-python. Run code ``python dataset_prep.py --datadir data``. After generated,  I got a error about our wav has two dim, it is not easy to slove.  Firstly, noisy_signal() function return two dim , we need to  change nb_augmented to 1 and ref https://www.geeksforgeeks.org/change-the-dimension-of-a-numpy-array, I shape our output into normal to extract  mfcc.

```python
        X = noisy_signal(X)        
        X.shape = (len(X[0]))
```
Nextly, we can used follow code to dispaly audio wav to see diff by ref :https://blog.csdn.net/weixin_39679367/article/details/115283072. 
```python
        # plt.plot(X)
        # plt.ylim([-0.5, 0.5])
        # plt.show()       
```
Finally, I run rsnet to tested. The result show that same network using noise is  improve?   I need to test again due my epoch and noise is not enough.   I improve noise numbers and it is work.  Then it work. The rsnet has good performance in noise, and noise has a influence for model.   But, init audio pertrain model 1DCNN overfit very much, Please not using this to train.


#### O 18  : generate pre-train model to vierifty influence  in  model
R ： Ok, I found pre-train will help me imporve .  but  I don't know how to train a  single model by using self-pertrian model.  
Update :  I found this per-train using error way. It cause our per-train has bad performance. 


D：  In this step, I want to verify per-train influence.  We can see some detail that audio and video per-train is not able to train in both times. So, I will use pre-train of 3DCNN and audio of not pre-train.   
Nextly, I want to know how to generate a pre-train model in our code.  I found following code is not saving a single model weight. So when I train a model, I need to change a single code to generate a pre-train model and verify validity.

```python
                    # torch.save(audio_model.state_dict(),
                    #            os.path.join(args.checkpointdir, 'fold_{}_msaf_ravdess_best.pth'.format(i + 1)))
```
After making that code to Mfcc single model like this code.  I  train audio model  without pre-train  in 50 epoch. Then  I use this pre-train model to a training again. The acc is improve from 46% to  45%,  not a improve?
 ```python
                    torch.save(audio_model.state_dict(),
                               os.path.join(args.checkpointdir, 'mfccNet/fold_{}_mfccNet_best.pth'.format(i + 1)))
```


update ：  We found previous work has a serious problem in data class. The author using many actor data to train a per-train model and using these per-train model to do val in less actor data. So  It cause we cann't train. So we re-shulffe our data allocation.  The key code as follow. We using a new flag  data_type to make all actor join  train. Not some actor is ingored. 
```python
        cnt = 0;
        for each_actor in actor_folds:
            for each_video in glob.glob(os.path.join(each_actor, "*.mp4")):
                cnt = cnt + 1;
                if (self.data_type == 1 and cnt % 5 != 0):                    
                    self.video_list.append(each_video)
                elif ((self.data_type == 0 and cnt % 5 == 0)):
                    self.video_list.append(each_video)
            actor_counter += 1
```
####  O  19  : load part of pertrain model for fusion 
R : ok, I load video model into fusion by custom. 
D: it is different due we want to change pre-train finally layer due it was changed.   I ref   https://blog.csdn.net/jackzhang11/article/details/108047586  to change my video model .  In this perhase, I met some questiones such as we need to   adjust direction is corrent[20] and change my fc name to fc1 for custom. [21].

```python 
        if args.train:  # load unimodal model weights
            video_model_path = os.path.join(args.checkpointdir,
                                            "resnext50/fold_{}_resnext50_best.pth".format(i + 1))
            video_model_checkpoint = torch.load(video_model_path) if use_cuda else \
                torch.load(video_model_path, map_location=torch.device('cpu'))
            #print(video_model_checkpoint)
            pre_video_model = torch.load(video_model_path)
            
        #     audio_model_path = os.path.join(args.checkpointdir,
        #                                     "mfccNet/fold_{}_mfccNet_best.pth".format(i + 1))
        #     audio_model_checkpoint = torch.load(audio_model_path) if use_cuda else \
        #         torch.load(audio_model_path, map_location=torch.device('cpu'))
        #     audio_model.load_state_dict(audio_model_checkpoint)
        state_dict = {k: v for k, v in pre_video_model.items() if k in cur_video_model_dict}
        #state_dict = {k:v for k,v in pre_video_model.items() if k in cur_video_model_dict}
        cur_video_model_dict.update(state_dict)
        video_model.load_state_dict(cur_video_model_dict)
        print(video_model)
  ```

#### O 20  : get fuison breakthourgh  according  previous work
R ： the previous work is 75% with pretain when set epoch is 70,  46% without pretain when set epoch is 50. But we using to get acc is. 


D ： we want to change this code by myself.  This okr require we need to understand many fusion method. So I need to ref [15]
1. change code using concate way , add way, multi way. 
-  +  add  function need to change fusion code and pre-load part of model. The result show that our 
- 
2. change code using  linear pooling to fusion. 
- +  pooling code ref [22].  The acc is  when epoch is 5.
```python

def bilinear_pooling(x,y):
    x_size = x.size()
    y_size = y.size()
    
 
    assert(x_size[:-1] == y_size[:-1])
 
    out_size = list(x_size)
    out_size[-1] = x_size[-1]*y_size[-1]   # 特征x和特征y维数之积
 
    x = x.view([-1,x_size[-1]])   # [N*C,F]
    y = y.view([-1,y_size[-1]])
 
    out_stack = []
    for i in range(x.size()[0]):
        out_stack.append(torch.ger(x[i],y[i]))   #torch.ger()向量的外积操作
 
    out = torch.stack(out_stack)  # 将list堆叠成tensor
 
    return out.view(out_size)   #[N,C,F*F]
```
3.  change code using attention machine.
- +  the perious code can achieve it, we just want to over it. the acc is  70%.


TODO:
4.  understand all fusion method by ref [15]
- + please pay attention pooling compute is not deep learning methd, it just a math calc, not need wx + b, so it is not deep learning in fusion.  
-  + ref https://github.com/wuzy361/MFN_keras/blob/master/MFN_imdb.py,  it introduce a easy to understand attention fusion method using keras to achieve.   I runed it in kaggle and get error about tf version(detail ref :https://www.kaggle.com/pengliu1997/notebookbb2d6b68f5/edit). I using  https://blog.csdn.net/sinat_28494049/article/details/104663053 to slove it .  but ref :https://blog.csdn.net/pku_langzi/article/details/81134900 can see that it may not can used directly, and need high aligin, but we can not achieve it .  
5. understand all fusion method  by ref [16]
- + these fusion model all has three model to fusion, the important model is text. So it maybe not suit. But these fusion method is SOTA in area. So, if some thing is worth to look, please read detail in late. 















### O2  writing master paper. 


#### O1 : writing chapter 6 

R :ok, I am  writing two project to achieve this paper, but some detail need to been add with fixxing step.

####  O2 : writing chapter 1

R: ok, but need to refix again.

D : In this step, I ref [9, 10] chapter framework and detail to writing my paper. I find [9] has good framework for master-paper can been  refed.  I  dive this paper into  four part : 1.1 background  1.2 emotion define 1.3 aiming and  meaning  1.4 recently search.  In background, I writing some meaning. In 1.2, it is hard to say something, so  I ref [9 10] about what they saying, then I read[11, 12] to understand what is emotion class. Then I understand [10] meaning  in emotion define.   1.3 ref [11].  1.4 ref  many paper. 
 
####  O3 : writing chapter 2


R: ok, but need to refix again.

D : 



####  O4 : writing chapter 3
R: 

D :  In this step, we need to finish my master-paper examples. So I running code. The result show that 
####  O4 : writing chapter 4
R: ok, 
D :   this chapter is not so important. I ref https://zhuanlan.zhihu.com/p/132655457 to writing my 3DresNext detail. And make a compare with 3DCNN.  Then we out put confusix result.   
####  O5 : writing chapter 5
R : ok , need to rebuild

####  O6 : writing  chapter 6 
R : ok , need to rebuild


####  O7 : fix latex error
R : done


1. Undefined control sequence.
these errores  have  six.  It due compiler version is not right ref :https://blog.csdn.net/kuan__/article/details/120850644 .  So it can been ingore. 
update ： this error is not able to ignoire.  We ref https://www.overleaf.com/learn/latex/Errors/Undefined_control_sequence to add \usepackage{xspace} into thesis.tex. All errores is ok.
2.  our pdf paper has black exitence. So I ref https://www.zhihu.com/question/266237548 to changed \documentclass[master,oneside]{scnuthesis}    in thesis.tex 
3. Download local software to run latex make sure our latex is not error. 



## reference 

1. [Git 过滤文件，控制上传](https://blog.csdn.net/hustpzb/article/details/8649545)
2. https://stackoverflow.com/questions/67703817/cant-import-plot-model-from-keras-utils
3. https://zhuanlan.zhihu.com/p/289024567
4. https://www.bilibili.com/video/BV1PV411k7ch?from=search&seid=3053220281673009205&spm_id_from=333.337.0.0
5. https://www.bilibili.com/video/BV1hZ4y1x7wp?from=search&seid=3053220281673009205&spm_id_from=333.337.0.0
6. https://github.com/skeletonnn/cfn-sr
7. https://github.com/anita-hu/MSAF 
8. https://zhuanlan.zhihu.com/p/378299521
9. https://kns.cnki.net/kcms/detail/detail.aspx?dbcode=CMFD&dbname=CMFD202101&filename=1020396104.nh&uniplatform=NZKPT&v=Gxr_5KbrxH0HepTiLQyator3HxwBlUVCMhCqDBLbEtCHEHnXGBGvlu-1iS7Hz5jV
10. https://kns.cnki.net/kcms/detail/detail.aspx?dbcode=CMFD&dbname=CMFD201902&filename=1019074545.nh&uniplatform=NZKPT&v=s9jxo9yqL5vd3eix3PjbiXFJa5uowo2r-A-tnaftK_8cF3sgTloOzdzumJg9GiiH
11. https://zh.wikipedia.org/wiki/%E6%83%85%E6%84%9F%E8%AE%A1%E7%AE%97
12. https://en.wikipedia.org/wiki/Emotion_classification
13. https://www.jastt.org/index.php/jasttpath/article/download/91/27 
14. https://zhuanlan.zhihu.com/p/75206669 
15. https://nakaizura.blog.csdn.net/article/details/105145074
16. https://github.com/declare-lab/multimodal-deep-learning
17. https://www.kaggle.com/pengliu1997/cnn-lstm/edit
18. https://segmentfault.com/a/1190000039771883
19. https://blog.csdn.net/yyhaohaoxuexi/article/details/88350343
20. https://blog.csdn.net/weixin_41529093/article/details/115946994?spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3.pc_relevant_paycolumn_v2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3.pc_relevant_paycolumn_v2&utm_relevant_index=6
21. https://blog.csdn.net/xzy5210123/article/details/88598436?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.pc_relevant_paycolumn_v2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.pc_relevant_paycolumn_v2&utm_relevant_index=2
22. https://blog.csdn.net/weijie_home/article/details/107331838?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-1.queryctrv2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-1.queryctrv2&utm_relevant_index=2