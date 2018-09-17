; ModuleID = 'si\String.c'
source_filename = "si\5CString.c"
target datalayout = "e-m:w-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.15.26729"

%struct.si_String = type { i64, i16, i8*, %struct.si_String*, i8 }

; Function Attrs: noinline nounwind optnone uwtable
define i32 @toUNICODE(%struct.si_String*) #0 {
  %2 = alloca %struct.si_String*, align 8
  %3 = alloca i8*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i16*, align 8
  store %struct.si_String* %0, %struct.si_String** %2, align 8
  %6 = load %struct.si_String*, %struct.si_String** %2, align 8
  %7 = getelementptr inbounds %struct.si_String, %struct.si_String* %6, i32 0, i32 2
  %8 = load i8*, i8** %7, align 8
  store i8* %8, i8** %3, align 8
  %9 = load i8*, i8** %3, align 8
  %10 = load %struct.si_String*, %struct.si_String** %2, align 8
  %11 = getelementptr inbounds %struct.si_String, %struct.si_String* %10, i32 0, i32 1
  %12 = load i16, i16* %11, align 8
  %13 = zext i16 %12 to i32
  %14 = call i32 @MultiByteToWideChar(i32 %13, i32 0, i8* %9, i32 0, i16* null, i32 0)
  store i32 %14, i32* %4, align 4
  %15 = load i32, i32* %4, align 4
  %16 = icmp sgt i32 %15, 0
  br i1 %16, label %17, label %41

; <label>:17:                                     ; preds = %1
  %18 = load i32, i32* %4, align 4
  %19 = sext i32 %18 to i64
  %20 = call noalias i8* @malloc(i64 %19)
  %21 = bitcast i8* %20 to i16*
  store i16* %21, i16** %5, align 8
  %22 = load i32, i32* %4, align 4
  %23 = load i16*, i16** %5, align 8
  %24 = load i8*, i8** %3, align 8
  %25 = load %struct.si_String*, %struct.si_String** %2, align 8
  %26 = getelementptr inbounds %struct.si_String, %struct.si_String* %25, i32 0, i32 1
  %27 = load i16, i16* %26, align 8
  %28 = zext i16 %27 to i32
  %29 = call i32 @MultiByteToWideChar(i32 %28, i32 0, i8* %24, i32 0, i16* %23, i32 %22)
  %30 = sext i32 %29 to i64
  %31 = load %struct.si_String*, %struct.si_String** %2, align 8
  %32 = getelementptr inbounds %struct.si_String, %struct.si_String* %31, i32 0, i32 0
  store i64 %30, i64* %32, align 8
  %33 = load i16*, i16** %5, align 8
  %34 = bitcast i16* %33 to i8*
  %35 = load %struct.si_String*, %struct.si_String** %2, align 8
  %36 = getelementptr inbounds %struct.si_String, %struct.si_String* %35, i32 0, i32 2
  store i8* %34, i8** %36, align 8
  %37 = load %struct.si_String*, %struct.si_String** %2, align 8
  %38 = getelementptr inbounds %struct.si_String, %struct.si_String* %37, i32 0, i32 1
  store i16 1200, i16* %38, align 8
  %39 = load %struct.si_String*, %struct.si_String** %2, align 8
  %40 = getelementptr inbounds %struct.si_String, %struct.si_String* %39, i32 0, i32 4
  store i8 1, i8* %40, align 8
  br label %41

; <label>:41:                                     ; preds = %17, %1
  %42 = load i32, i32* %4, align 4
  ret i32 %42
}

declare dllimport i32 @MultiByteToWideChar(i32, i32, i8*, i32, i16*, i32) #1

declare noalias i8* @malloc(i64) #1

; Function Attrs: noinline nounwind optnone uwtable
define void @si_String_init(%struct.si_String*, i16, i8*, i64, %struct.si_String*) #0 {
  %6 = alloca %struct.si_String*, align 8
  %7 = alloca i64, align 8
  %8 = alloca i8*, align 8
  %9 = alloca i16, align 2
  %10 = alloca %struct.si_String*, align 8
  store %struct.si_String* %4, %struct.si_String** %6, align 8
  store i64 %3, i64* %7, align 8
  store i8* %2, i8** %8, align 8
  store i16 %1, i16* %9, align 2
  store %struct.si_String* %0, %struct.si_String** %10, align 8
  %11 = load i8*, i8** %8, align 8
  %12 = load %struct.si_String*, %struct.si_String** %10, align 8
  %13 = getelementptr inbounds %struct.si_String, %struct.si_String* %12, i32 0, i32 2
  store i8* %11, i8** %13, align 8
  %14 = load i64, i64* %7, align 8
  %15 = load %struct.si_String*, %struct.si_String** %10, align 8
  %16 = getelementptr inbounds %struct.si_String, %struct.si_String* %15, i32 0, i32 0
  store i64 %14, i64* %16, align 8
  %17 = load i16, i16* %9, align 2
  %18 = load %struct.si_String*, %struct.si_String** %10, align 8
  %19 = getelementptr inbounds %struct.si_String, %struct.si_String* %18, i32 0, i32 1
  store i16 %17, i16* %19, align 8
  %20 = load %struct.si_String*, %struct.si_String** %6, align 8
  %21 = load %struct.si_String*, %struct.si_String** %10, align 8
  %22 = getelementptr inbounds %struct.si_String, %struct.si_String* %21, i32 0, i32 3
  store %struct.si_String* %20, %struct.si_String** %22, align 8
  %23 = load %struct.si_String*, %struct.si_String** %10, align 8
  %24 = getelementptr inbounds %struct.si_String, %struct.si_String* %23, i32 0, i32 4
  store i8 0, i8* %24, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define i64 @si_String_GET_size(%struct.si_String*) #0 {
  %2 = alloca %struct.si_String*, align 8
  store %struct.si_String* %0, %struct.si_String** %2, align 8
  %3 = load %struct.si_String*, %struct.si_String** %2, align 8
  %4 = getelementptr inbounds %struct.si_String, %struct.si_String* %3, i32 0, i32 0
  %5 = load i64, i64* %4, align 8
  ret i64 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define i16 @si_String_at(%struct.si_String*, i64) #0 {
  %3 = alloca i16, align 2
  %4 = alloca i64, align 8
  %5 = alloca %struct.si_String*, align 8
  %6 = alloca i16*, align 8
  store i64 %1, i64* %4, align 8
  store %struct.si_String* %0, %struct.si_String** %5, align 8
  %7 = load i64, i64* %4, align 8
  %8 = load %struct.si_String*, %struct.si_String** %5, align 8
  %9 = getelementptr inbounds %struct.si_String, %struct.si_String* %8, i32 0, i32 0
  %10 = load i64, i64* %9, align 8
  %11 = icmp uge i64 %7, %10
  br i1 %11, label %12, label %13

; <label>:12:                                     ; preds = %2
  store i16 -1, i16* %3, align 2
  br label %22

; <label>:13:                                     ; preds = %2
  %14 = load %struct.si_String*, %struct.si_String** %5, align 8
  %15 = getelementptr inbounds %struct.si_String, %struct.si_String* %14, i32 0, i32 2
  %16 = load i8*, i8** %15, align 8
  %17 = bitcast i8* %16 to i16*
  store i16* %17, i16** %6, align 8
  %18 = load i16*, i16** %6, align 8
  %19 = load i64, i64* %4, align 8
  %20 = getelementptr inbounds i16, i16* %18, i64 %19
  %21 = load i16, i16* %20, align 2
  store i16 %21, i16* %3, align 2
  br label %22

; <label>:22:                                     ; preds = %13, %12
  %23 = load i16, i16* %3, align 2
  ret i16 %23
}

; Function Attrs: noinline nounwind optnone uwtable
define i8* @si_String_Cast_i8_ptr(%struct.si_String*) #0 {
  %2 = alloca %struct.si_String*, align 8
  store %struct.si_String* %0, %struct.si_String** %2, align 8
  %3 = load %struct.si_String*, %struct.si_String** %2, align 8
  %4 = getelementptr inbounds %struct.si_String, %struct.si_String* %3, i32 0, i32 2
  %5 = load i8*, i8** %4, align 8
  ret i8* %5
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.linker.options = !{!0, !0}
!llvm.module.flags = !{!1, !2}
!llvm.ident = !{!3}

!0 = !{!"/DEFAULTLIB:uuid.lib"}
!1 = !{i32 1, !"wchar_size", i32 2}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"clang version 6.0.1 (tags/RELEASE_601/final)"}
