; ModuleID = 'si\String.c'
source_filename = "si\5CString.c"
target datalayout = "e-m:w-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.16.27024"

%struct.si_Charset = type { i16 }
%struct.si_String = type { i64, i16*, %struct.si_String*, i16 }

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @si_Charset_Init(%struct.si_Charset*, i64) #0 {
  %3 = alloca i64, align 8
  %4 = alloca %struct.si_Charset*, align 8
  store i64 %1, i64* %3, align 8
  store %struct.si_Charset* %0, %struct.si_Charset** %4, align 8
  %5 = load i64, i64* %3, align 8
  %6 = trunc i64 %5 to i16
  %7 = load %struct.si_Charset*, %struct.si_Charset** %4, align 8
  %8 = getelementptr inbounds %struct.si_Charset, %struct.si_Charset* %7, i32 0, i32 0
  store i16 %6, i16* %8, align 2
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @si_String_Init(%struct.si_String*, i8*, i64, i16) #0 {
  %5 = alloca i16, align 2
  %6 = alloca i64, align 8
  %7 = alloca i8*, align 8
  %8 = alloca %struct.si_String*, align 8
  store i16 %3, i16* %5, align 2
  store i64 %2, i64* %6, align 8
  store i8* %1, i8** %7, align 8
  store %struct.si_String* %0, %struct.si_String** %8, align 8
  %9 = load i8*, i8** %7, align 8
  %10 = bitcast i8* %9 to i16*
  %11 = load %struct.si_String*, %struct.si_String** %8, align 8
  %12 = getelementptr inbounds %struct.si_String, %struct.si_String* %11, i32 0, i32 1
  store i16* %10, i16** %12, align 8
  %13 = load i64, i64* %6, align 8
  %14 = load %struct.si_String*, %struct.si_String** %8, align 8
  %15 = getelementptr inbounds %struct.si_String, %struct.si_String* %14, i32 0, i32 0
  store i64 %13, i64* %15, align 8
  %16 = load i16, i16* %5, align 2
  %17 = load %struct.si_String*, %struct.si_String** %8, align 8
  %18 = getelementptr inbounds %struct.si_String, %struct.si_String* %17, i32 0, i32 3
  store i16 %16, i16* %18, align 8
  %19 = load %struct.si_String*, %struct.si_String** %8, align 8
  %20 = getelementptr inbounds %struct.si_String, %struct.si_String* %19, i32 0, i32 2
  store %struct.si_String* null, %struct.si_String** %20, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @si_String_Finalize(%struct.si_String*) #0 {
  %2 = alloca %struct.si_String*, align 8
  store %struct.si_String* %0, %struct.si_String** %2, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @si_String_Splice(%struct.si_String*, i64, i64) #0 {
  %4 = alloca i64, align 8
  %5 = alloca i64, align 8
  %6 = alloca %struct.si_String*, align 8
  store i64 %2, i64* %4, align 8
  store i64 %1, i64* %5, align 8
  store %struct.si_String* %0, %struct.si_String** %6, align 8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i64 @si_String_GET_size(%struct.si_String*) #0 {
  %2 = alloca %struct.si_String*, align 8
  store %struct.si_String* %0, %struct.si_String** %2, align 8
  %3 = load %struct.si_String*, %struct.si_String** %2, align 8
  %4 = getelementptr inbounds %struct.si_String, %struct.si_String* %3, i32 0, i32 0
  %5 = load i64, i64* %4, align 8
  ret i64 %5
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i16 @si_String_at(%struct.si_String*, i64) #0 {
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
  br label %21

; <label>:13:                                     ; preds = %2
  %14 = load %struct.si_String*, %struct.si_String** %5, align 8
  %15 = getelementptr inbounds %struct.si_String, %struct.si_String* %14, i32 0, i32 1
  %16 = load i16*, i16** %15, align 8
  store i16* %16, i16** %6, align 8
  %17 = load i16*, i16** %6, align 8
  %18 = load i64, i64* %4, align 8
  %19 = getelementptr inbounds i16, i16* %17, i64 %18
  %20 = load i16, i16* %19, align 2
  store i16 %20, i16* %3, align 2
  br label %21

; <label>:21:                                     ; preds = %13, %12
  %22 = load i16, i16* %3, align 2
  ret i16 %22
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i8* @si_String_Cast_i8_ptr(%struct.si_String*) #0 {
  %2 = alloca %struct.si_String*, align 8
  store %struct.si_String* %0, %struct.si_String** %2, align 8
  %3 = load %struct.si_String*, %struct.si_String** %2, align 8
  %4 = getelementptr inbounds %struct.si_String, %struct.si_String* %3, i32 0, i32 1
  %5 = load i16*, i16** %4, align 8
  %6 = bitcast i16* %5 to i8*
  ret i8* %6
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.linker.options = !{!0, !0}
!llvm.module.flags = !{!1, !2}
!llvm.ident = !{!3}

!0 = !{!"/DEFAULTLIB:uuid.lib"}
!1 = !{i32 1, !"wchar_size", i32 2}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"clang version 7.0.0 (tags/RELEASE_700/final)"}
