import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AddEditPcPartComponent } from './add-edit-pc-part.component';

describe('AddEditPcPartComponent', () => {
  let component: AddEditPcPartComponent;
  let fixture: ComponentFixture<AddEditPcPartComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ AddEditPcPartComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(AddEditPcPartComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
