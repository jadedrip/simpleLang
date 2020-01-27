; ModuleID = 'si.c'
source_filename = "si.c"
target datalayout = "e-m:w-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.24.28315"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @si() #0 {
  ret i32 add nsw (i32 add nsw (i32 add nsw (i32 add nsw (i32 ptrtoint (i8* (i32, i64)* @createObject to i32), i32 ptrtoint (void (i8*, void (i8*)*)* @freeObject to i32)), i32 ptrtoint (i32 (i8*)* @referenceIncrease to i32)), i32 ptrtoint (i8* (i64, i32)* @createArray to i32)), i32 ptrtoint (void (i8**, i64, i8*)* @arrayLet to i32))
}

declare dso_local i8* @createObject(i32, i64) #1

declare dso_local void @freeObject(i8*, void (i8*)*) #1

declare dso_local i32 @referenceIncrease(i8*) #1

declare dso_local i8* @createArray(i64, i32) #1

declare dso_local void @arrayLet(i8**, i64, i8*) #1

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{!"clang version 9.0.0 (tags/RELEASE_900/final)"}
