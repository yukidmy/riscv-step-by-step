# LAZY LOADING
このステップでは lazy loading について説明します. lazy loading
はプログラムをメモリにロードする手法の一つで,
タスクの実行前にプログラムをメモリにロードするのではなく,
タスクがページにアクセスしたタイミングでそのページにプログラムがロードされていなければページにプログラムをロードします.
lazy loading は実行に必要なプログラムのページのみロードされるため,
少ないメモリでプログラムを実行できます.
またプログラムの開始前にプログラムをロードしないため実行開始時間を短くできるというメリットがあります.
一方プログラムがロードされていないページへのアクセス時間が長くなるとうデメリットがあります.
仮想アドレスの導入によりプログラムをロードする手法に選択肢が増えます.

## lazy loading シーケンス
今回は以下の流れで lazy loading を動作させます.
1. タスクの PTE の準備
1. タスクの実行開始
1. ページフォルトハンドリング
1. ページフォルト要因とエラーアドレスの確認
1. プログラムセグメントからプログラムをロード
1. ページフォルトが発生したアドレスのページにプログラムをロードする.
1. ページの PTE のVビットを設定
1. タスクの再開
