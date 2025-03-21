#!/bin/bash

# 所有被刪除的檔案檔名（根據 git ls-files --deleted）
filenames=(
  "10019 - Funny Encryption Method.cpp"
  "10035 - Primary Arithmetic.cpp"
  "10041 - Vitos Family.cpp"
  "10050 - Hartals.cpp"
  "10055 - Hashmat the Brave Warrior.cpp"
  "10057 - A mid-summer night dream.cpp"
  "10062 - Tell me the frequencies.cpp"
  "10190 - Divide, But Not Quite Conquer.cpp"
  "10193 - All You Need Is Love.cpp"
  "10221 - Statellites.cpp"
  "10226 - Hardwood Species.cpp"
  "10235 - Simply Emirp.cpp"
  "10242 - Fourth Point.cpp"
  "10420 - List of Conquests.cpp"
  "10642 - Can You Solve It.cpp"
  "10908 - Largest Square.cpp"
  "10922 - 2 the 9s.cpp"
  "10931 - Parity.cpp"
  "11005 - Cheapest Base.cpp"
  "11417 - GCD.cpp"
  "12650 - Dangerous Dive.cpp"
  "299 - Train Swapping.cpp"
  "948 - Fibonaccimal Base.cpp"
)

for filename in "${filenames[@]}"; do
  echo ""
  echo "▶️ 處理檔案: $filename"

  # 找舊的 Git path
  old_path=$(git ls-files --deleted | grep "$filename")
  if [ -z "$old_path" ]; then
    echo "❌ 找不到舊路徑"
    continue
  fi

  # 找原本的提交時間
  COMMIT_DATE=$(git log --pretty=format:%ai -n 1 -- "$old_path")
  if [ -z "$COMMIT_DATE" ]; then
    echo "❌ 找不到提交時間"
    continue
  fi

  # 找新檔案位置
  new_path=$(find . -type f -name "$filename" | head -n 1)
  if [ -z "$new_path" ]; then
    echo "❌ 找不到新檔案"
    continue
  fi

  echo "✅ 恢復提交時間:"
  echo "   🔹 新檔案: $new_path"
  echo "   🔹 舊路徑: $old_path"
  echo "   🔹 提交時間: $COMMIT_DATE"

  # commit
  git add "$new_path"
  GIT_COMMITTER_DATE="$COMMIT_DATE" git commit -m "Restore $new_path" --date "$COMMIT_DATE"
done
