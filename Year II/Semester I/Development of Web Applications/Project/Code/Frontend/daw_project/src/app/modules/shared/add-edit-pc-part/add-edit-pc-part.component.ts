import { Component, Inject, Injectable, OnInit } from '@angular/core';
import { AbstractControl, FormArray, FormControl, FormGroup } from '@angular/forms';
import { MatDialogRef, MAT_DIALOG_DATA } from '@angular/material/dialog';
import { PcComponentsService } from 'src/app/services/pc-components.service';

@Component({
  selector: 'app-add-edit-pc-part',
  templateUrl: './add-edit-pc-part.component.html',
  styleUrls: ['./add-edit-pc-part.component.scss']
})
export class AddEditPcPartComponent implements OnInit {

  public pcComponentForm: FormGroup = new FormGroup({
    componentId: new FormControl(null),
    componentName: new FormControl(''),
    seller: new FormControl(''),
    recommendedForGaming: new FormControl(false),
    price: new FormControl(null)
  });
  public title: any;

  constructor(
    @Inject(MAT_DIALOG_DATA) public data: any,
    private pcComponentsService: PcComponentsService,
    public dialogRef: MatDialogRef<AddEditPcPartComponent>
  ) {
    console.log(this.data);
    if (data.pcComponent) {
      this.title = 'Edit Component';
      this.pcComponentForm.patchValue(this.data.pcComponent);
    } else {
      this.title = 'Add Component';
    }
  }

  get componentId(): AbstractControl {
    return this.pcComponentForm?.get('componentId') as AbstractControl;
  }
  get componentName(): AbstractControl {
    return this.pcComponentForm?.get('componentName') as AbstractControl;
  }
  get seller(): AbstractControl {
    return this.pcComponentForm?.get('seller') as AbstractControl;
  }
  get recommendedForGaming(): AbstractControl {
    return this.pcComponentForm?.get('recommendedForGaming') as AbstractControl;
  }
  get price(): AbstractControl {
    return this.pcComponentForm?.get('price') as AbstractControl;
  }

  ngOnInit(): void {
  }

  public addComponent(): void {
    this.pcComponentsService.addComponent(this.pcComponentForm.value).subscribe({
      next: (result) => {
        this.dialogRef.close(result);
      },
      error: (e) => console.error(e)
    });
  }

  public editComponent(): void {
    this.pcComponentsService.editComponent(this.pcComponentForm.value).subscribe({
      next: (result) => {
        this.dialogRef.close(result);
      },
      error: (e) => console.error(e)
    });
  }

}
